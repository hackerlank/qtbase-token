begin_unit
begin_comment
comment|/******************************************************************************** ** Form generated from reading UI file 'calculator.ui' ** ** Created: Fri Sep 4 10:17:12 2009 **      by: Qt User Interface Compiler version 4.6.0 ** ** WARNING! All changes made in this file will be lost when recompiling UI file! ********************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|CALCULATOR_H
end_ifndef
begin_define
DECL|macro|CALCULATOR_H
define|#
directive|define
name|CALCULATOR_H
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
file|<QtWidgets/QHeaderView>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QLineEdit>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QToolButton>
end_include
begin_include
include|#
directive|include
file|<QtWidgets/QWidget>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|Ui_Calculator
block|{
name|public
label|:
name|QToolButton
modifier|*
name|backspaceButton
decl_stmt|;
name|QToolButton
modifier|*
name|clearButton
decl_stmt|;
name|QToolButton
modifier|*
name|clearAllButton
decl_stmt|;
name|QToolButton
modifier|*
name|clearMemoryButton
decl_stmt|;
name|QToolButton
modifier|*
name|readMemoryButton
decl_stmt|;
name|QToolButton
modifier|*
name|setMemoryButton
decl_stmt|;
name|QToolButton
modifier|*
name|addToMemoryButton
decl_stmt|;
name|QToolButton
modifier|*
name|sevenButton
decl_stmt|;
name|QToolButton
modifier|*
name|eightButton
decl_stmt|;
name|QToolButton
modifier|*
name|nineButton
decl_stmt|;
name|QToolButton
modifier|*
name|fourButton
decl_stmt|;
name|QToolButton
modifier|*
name|fiveButton
decl_stmt|;
name|QToolButton
modifier|*
name|sixButton
decl_stmt|;
name|QToolButton
modifier|*
name|oneButton
decl_stmt|;
name|QToolButton
modifier|*
name|twoButton
decl_stmt|;
name|QToolButton
modifier|*
name|threeButton
decl_stmt|;
name|QToolButton
modifier|*
name|zeroButton
decl_stmt|;
name|QToolButton
modifier|*
name|pointButton
decl_stmt|;
name|QToolButton
modifier|*
name|changeSignButton
decl_stmt|;
name|QToolButton
modifier|*
name|plusButton
decl_stmt|;
name|QToolButton
modifier|*
name|divisionButton
decl_stmt|;
name|QToolButton
modifier|*
name|timesButton
decl_stmt|;
name|QToolButton
modifier|*
name|minusButton
decl_stmt|;
name|QToolButton
modifier|*
name|squareRootButton
decl_stmt|;
name|QToolButton
modifier|*
name|powerButton
decl_stmt|;
name|QToolButton
modifier|*
name|reciprocalButton
decl_stmt|;
name|QToolButton
modifier|*
name|equalButton
decl_stmt|;
name|QLineEdit
modifier|*
name|display
decl_stmt|;
name|void
name|setupUi
parameter_list|(
name|QWidget
modifier|*
name|Calculator
parameter_list|)
block|{
if|if
condition|(
name|Calculator
operator|->
name|objectName
argument_list|()
operator|.
name|isEmpty
argument_list|()
condition|)
name|Calculator
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"Calculator"
argument_list|)
argument_list|)
expr_stmt|;
name|Calculator
operator|->
name|resize
argument_list|(
literal|314
argument_list|,
literal|301
argument_list|)
expr_stmt|;
name|QSizePolicy
name|sizePolicy
argument_list|(
name|QSizePolicy
operator|::
name|Fixed
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
name|Calculator
operator|->
name|sizePolicy
argument_list|()
operator|.
name|hasHeightForWidth
argument_list|()
argument_list|)
expr_stmt|;
name|Calculator
operator|->
name|setSizePolicy
argument_list|(
name|sizePolicy
argument_list|)
expr_stmt|;
name|Calculator
operator|->
name|setMinimumSize
argument_list|(
name|QSize
argument_list|(
literal|314
argument_list|,
literal|301
argument_list|)
argument_list|)
expr_stmt|;
name|Calculator
operator|->
name|setMaximumSize
argument_list|(
name|QSize
argument_list|(
literal|314
argument_list|,
literal|301
argument_list|)
argument_list|)
expr_stmt|;
name|backspaceButton
operator|=
name|new
name|QToolButton
argument_list|(
name|Calculator
argument_list|)
expr_stmt|;
name|backspaceButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"backspaceButton"
argument_list|)
argument_list|)
expr_stmt|;
name|backspaceButton
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|10
argument_list|,
literal|50
argument_list|,
literal|91
argument_list|,
literal|41
argument_list|)
argument_list|)
expr_stmt|;
name|clearButton
operator|=
name|new
name|QToolButton
argument_list|(
name|Calculator
argument_list|)
expr_stmt|;
name|clearButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"clearButton"
argument_list|)
argument_list|)
expr_stmt|;
name|clearButton
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|110
argument_list|,
literal|50
argument_list|,
literal|91
argument_list|,
literal|41
argument_list|)
argument_list|)
expr_stmt|;
name|clearAllButton
operator|=
name|new
name|QToolButton
argument_list|(
name|Calculator
argument_list|)
expr_stmt|;
name|clearAllButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"clearAllButton"
argument_list|)
argument_list|)
expr_stmt|;
name|clearAllButton
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|210
argument_list|,
literal|50
argument_list|,
literal|91
argument_list|,
literal|41
argument_list|)
argument_list|)
expr_stmt|;
name|clearMemoryButton
operator|=
name|new
name|QToolButton
argument_list|(
name|Calculator
argument_list|)
expr_stmt|;
name|clearMemoryButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"clearMemoryButton"
argument_list|)
argument_list|)
expr_stmt|;
name|clearMemoryButton
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|10
argument_list|,
literal|100
argument_list|,
literal|41
argument_list|,
literal|41
argument_list|)
argument_list|)
expr_stmt|;
name|readMemoryButton
operator|=
name|new
name|QToolButton
argument_list|(
name|Calculator
argument_list|)
expr_stmt|;
name|readMemoryButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"readMemoryButton"
argument_list|)
argument_list|)
expr_stmt|;
name|readMemoryButton
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|10
argument_list|,
literal|150
argument_list|,
literal|41
argument_list|,
literal|41
argument_list|)
argument_list|)
expr_stmt|;
name|setMemoryButton
operator|=
name|new
name|QToolButton
argument_list|(
name|Calculator
argument_list|)
expr_stmt|;
name|setMemoryButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"setMemoryButton"
argument_list|)
argument_list|)
expr_stmt|;
name|setMemoryButton
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|10
argument_list|,
literal|200
argument_list|,
literal|41
argument_list|,
literal|41
argument_list|)
argument_list|)
expr_stmt|;
name|addToMemoryButton
operator|=
name|new
name|QToolButton
argument_list|(
name|Calculator
argument_list|)
expr_stmt|;
name|addToMemoryButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"addToMemoryButton"
argument_list|)
argument_list|)
expr_stmt|;
name|addToMemoryButton
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|10
argument_list|,
literal|250
argument_list|,
literal|41
argument_list|,
literal|41
argument_list|)
argument_list|)
expr_stmt|;
name|sevenButton
operator|=
name|new
name|QToolButton
argument_list|(
name|Calculator
argument_list|)
expr_stmt|;
name|sevenButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"sevenButton"
argument_list|)
argument_list|)
expr_stmt|;
name|sevenButton
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|60
argument_list|,
literal|100
argument_list|,
literal|41
argument_list|,
literal|41
argument_list|)
argument_list|)
expr_stmt|;
name|eightButton
operator|=
name|new
name|QToolButton
argument_list|(
name|Calculator
argument_list|)
expr_stmt|;
name|eightButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"eightButton"
argument_list|)
argument_list|)
expr_stmt|;
name|eightButton
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|110
argument_list|,
literal|100
argument_list|,
literal|41
argument_list|,
literal|41
argument_list|)
argument_list|)
expr_stmt|;
name|nineButton
operator|=
name|new
name|QToolButton
argument_list|(
name|Calculator
argument_list|)
expr_stmt|;
name|nineButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"nineButton"
argument_list|)
argument_list|)
expr_stmt|;
name|nineButton
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|160
argument_list|,
literal|100
argument_list|,
literal|41
argument_list|,
literal|41
argument_list|)
argument_list|)
expr_stmt|;
name|fourButton
operator|=
name|new
name|QToolButton
argument_list|(
name|Calculator
argument_list|)
expr_stmt|;
name|fourButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"fourButton"
argument_list|)
argument_list|)
expr_stmt|;
name|fourButton
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|60
argument_list|,
literal|150
argument_list|,
literal|41
argument_list|,
literal|41
argument_list|)
argument_list|)
expr_stmt|;
name|fiveButton
operator|=
name|new
name|QToolButton
argument_list|(
name|Calculator
argument_list|)
expr_stmt|;
name|fiveButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"fiveButton"
argument_list|)
argument_list|)
expr_stmt|;
name|fiveButton
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|110
argument_list|,
literal|150
argument_list|,
literal|41
argument_list|,
literal|41
argument_list|)
argument_list|)
expr_stmt|;
name|sixButton
operator|=
name|new
name|QToolButton
argument_list|(
name|Calculator
argument_list|)
expr_stmt|;
name|sixButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"sixButton"
argument_list|)
argument_list|)
expr_stmt|;
name|sixButton
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|160
argument_list|,
literal|150
argument_list|,
literal|41
argument_list|,
literal|41
argument_list|)
argument_list|)
expr_stmt|;
name|oneButton
operator|=
name|new
name|QToolButton
argument_list|(
name|Calculator
argument_list|)
expr_stmt|;
name|oneButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"oneButton"
argument_list|)
argument_list|)
expr_stmt|;
name|oneButton
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|60
argument_list|,
literal|200
argument_list|,
literal|41
argument_list|,
literal|41
argument_list|)
argument_list|)
expr_stmt|;
name|twoButton
operator|=
name|new
name|QToolButton
argument_list|(
name|Calculator
argument_list|)
expr_stmt|;
name|twoButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"twoButton"
argument_list|)
argument_list|)
expr_stmt|;
name|twoButton
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|110
argument_list|,
literal|200
argument_list|,
literal|41
argument_list|,
literal|41
argument_list|)
argument_list|)
expr_stmt|;
name|threeButton
operator|=
name|new
name|QToolButton
argument_list|(
name|Calculator
argument_list|)
expr_stmt|;
name|threeButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"threeButton"
argument_list|)
argument_list|)
expr_stmt|;
name|threeButton
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|160
argument_list|,
literal|200
argument_list|,
literal|41
argument_list|,
literal|41
argument_list|)
argument_list|)
expr_stmt|;
name|zeroButton
operator|=
name|new
name|QToolButton
argument_list|(
name|Calculator
argument_list|)
expr_stmt|;
name|zeroButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"zeroButton"
argument_list|)
argument_list|)
expr_stmt|;
name|zeroButton
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|60
argument_list|,
literal|250
argument_list|,
literal|41
argument_list|,
literal|41
argument_list|)
argument_list|)
expr_stmt|;
name|pointButton
operator|=
name|new
name|QToolButton
argument_list|(
name|Calculator
argument_list|)
expr_stmt|;
name|pointButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"pointButton"
argument_list|)
argument_list|)
expr_stmt|;
name|pointButton
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|110
argument_list|,
literal|250
argument_list|,
literal|41
argument_list|,
literal|41
argument_list|)
argument_list|)
expr_stmt|;
name|changeSignButton
operator|=
name|new
name|QToolButton
argument_list|(
name|Calculator
argument_list|)
expr_stmt|;
name|changeSignButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"changeSignButton"
argument_list|)
argument_list|)
expr_stmt|;
name|changeSignButton
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|160
argument_list|,
literal|250
argument_list|,
literal|41
argument_list|,
literal|41
argument_list|)
argument_list|)
expr_stmt|;
name|plusButton
operator|=
name|new
name|QToolButton
argument_list|(
name|Calculator
argument_list|)
expr_stmt|;
name|plusButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"plusButton"
argument_list|)
argument_list|)
expr_stmt|;
name|plusButton
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|210
argument_list|,
literal|250
argument_list|,
literal|41
argument_list|,
literal|41
argument_list|)
argument_list|)
expr_stmt|;
name|divisionButton
operator|=
name|new
name|QToolButton
argument_list|(
name|Calculator
argument_list|)
expr_stmt|;
name|divisionButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"divisionButton"
argument_list|)
argument_list|)
expr_stmt|;
name|divisionButton
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|210
argument_list|,
literal|100
argument_list|,
literal|41
argument_list|,
literal|41
argument_list|)
argument_list|)
expr_stmt|;
name|timesButton
operator|=
name|new
name|QToolButton
argument_list|(
name|Calculator
argument_list|)
expr_stmt|;
name|timesButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"timesButton"
argument_list|)
argument_list|)
expr_stmt|;
name|timesButton
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|210
argument_list|,
literal|150
argument_list|,
literal|41
argument_list|,
literal|41
argument_list|)
argument_list|)
expr_stmt|;
name|minusButton
operator|=
name|new
name|QToolButton
argument_list|(
name|Calculator
argument_list|)
expr_stmt|;
name|minusButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"minusButton"
argument_list|)
argument_list|)
expr_stmt|;
name|minusButton
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|210
argument_list|,
literal|200
argument_list|,
literal|41
argument_list|,
literal|41
argument_list|)
argument_list|)
expr_stmt|;
name|squareRootButton
operator|=
name|new
name|QToolButton
argument_list|(
name|Calculator
argument_list|)
expr_stmt|;
name|squareRootButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"squareRootButton"
argument_list|)
argument_list|)
expr_stmt|;
name|squareRootButton
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|260
argument_list|,
literal|100
argument_list|,
literal|41
argument_list|,
literal|41
argument_list|)
argument_list|)
expr_stmt|;
name|powerButton
operator|=
name|new
name|QToolButton
argument_list|(
name|Calculator
argument_list|)
expr_stmt|;
name|powerButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"powerButton"
argument_list|)
argument_list|)
expr_stmt|;
name|powerButton
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|260
argument_list|,
literal|150
argument_list|,
literal|41
argument_list|,
literal|41
argument_list|)
argument_list|)
expr_stmt|;
name|reciprocalButton
operator|=
name|new
name|QToolButton
argument_list|(
name|Calculator
argument_list|)
expr_stmt|;
name|reciprocalButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"reciprocalButton"
argument_list|)
argument_list|)
expr_stmt|;
name|reciprocalButton
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|260
argument_list|,
literal|200
argument_list|,
literal|41
argument_list|,
literal|41
argument_list|)
argument_list|)
expr_stmt|;
name|equalButton
operator|=
name|new
name|QToolButton
argument_list|(
name|Calculator
argument_list|)
expr_stmt|;
name|equalButton
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"equalButton"
argument_list|)
argument_list|)
expr_stmt|;
name|equalButton
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|260
argument_list|,
literal|250
argument_list|,
literal|41
argument_list|,
literal|41
argument_list|)
argument_list|)
expr_stmt|;
name|display
operator|=
name|new
name|QLineEdit
argument_list|(
name|Calculator
argument_list|)
expr_stmt|;
name|display
operator|->
name|setObjectName
argument_list|(
name|QStringLiteral
argument_list|(
literal|"display"
argument_list|)
argument_list|)
expr_stmt|;
name|display
operator|->
name|setGeometry
argument_list|(
name|QRect
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|,
literal|291
argument_list|,
literal|31
argument_list|)
argument_list|)
expr_stmt|;
name|display
operator|->
name|setMaxLength
argument_list|(
literal|15
argument_list|)
expr_stmt|;
name|display
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
name|display
operator|->
name|setReadOnly
argument_list|(
name|true
argument_list|)
expr_stmt|;
name|retranslateUi
argument_list|(
name|Calculator
argument_list|)
expr_stmt|;
name|QMetaObject
operator|::
name|connectSlotsByName
argument_list|(
name|Calculator
argument_list|)
expr_stmt|;
block|}
comment|// setupUi
name|void
name|retranslateUi
parameter_list|(
name|QWidget
modifier|*
name|Calculator
parameter_list|)
block|{
name|Calculator
operator|->
name|setWindowTitle
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Calculator"
argument_list|,
literal|"Calculator"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|backspaceButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Calculator"
argument_list|,
literal|"Backspace"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|clearButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Calculator"
argument_list|,
literal|"Clear"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|clearAllButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Calculator"
argument_list|,
literal|"Clear All"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|clearMemoryButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Calculator"
argument_list|,
literal|"MC"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|readMemoryButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Calculator"
argument_list|,
literal|"MR"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|setMemoryButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Calculator"
argument_list|,
literal|"MS"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|addToMemoryButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Calculator"
argument_list|,
literal|"M+"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|sevenButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Calculator"
argument_list|,
literal|"7"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|eightButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Calculator"
argument_list|,
literal|"8"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|nineButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Calculator"
argument_list|,
literal|"9"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|fourButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Calculator"
argument_list|,
literal|"4"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|fiveButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Calculator"
argument_list|,
literal|"5"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|sixButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Calculator"
argument_list|,
literal|"6"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|oneButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Calculator"
argument_list|,
literal|"1"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|twoButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Calculator"
argument_list|,
literal|"2"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|threeButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Calculator"
argument_list|,
literal|"3"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|zeroButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Calculator"
argument_list|,
literal|"0"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|pointButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Calculator"
argument_list|,
literal|"."
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|changeSignButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Calculator"
argument_list|,
literal|"+-"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|plusButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Calculator"
argument_list|,
literal|"+"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|divisionButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Calculator"
argument_list|,
literal|"/"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|timesButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Calculator"
argument_list|,
literal|"*"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|minusButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Calculator"
argument_list|,
literal|"-"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|squareRootButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Calculator"
argument_list|,
literal|"Sqrt"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|powerButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Calculator"
argument_list|,
literal|"x^2"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|reciprocalButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Calculator"
argument_list|,
literal|"1/x"
argument_list|,
literal|0
argument_list|,
name|QApplication
operator|::
name|UnicodeUTF8
argument_list|)
argument_list|)
expr_stmt|;
name|equalButton
operator|->
name|setText
argument_list|(
name|QApplication
operator|::
name|translate
argument_list|(
literal|"Calculator"
argument_list|,
literal|"="
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
name|Calculator
range|:
name|public
name|Ui_Calculator
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
comment|// CALCULATOR_H
end_comment
end_unit
