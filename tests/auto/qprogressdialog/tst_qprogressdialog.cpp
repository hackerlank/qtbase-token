begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qcoreapplication.h>
end_include
begin_include
include|#
directive|include
file|<qdebug.h>
end_include
begin_include
include|#
directive|include
file|<qprogressdialog.h>
end_include
begin_include
include|#
directive|include
file|<qlabel.h>
end_include
begin_comment
comment|//TESTED_CLASS=
end_comment
begin_comment
comment|//TESTED_FILES=
end_comment
begin_class
DECL|class|tst_QProgressDialog
class|class
name|tst_QProgressDialog
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QProgressDialog
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QProgressDialog
parameter_list|()
destructor_decl|;
private|private
name|slots
private|:
name|void
name|getSetCheck
parameter_list|()
function_decl|;
name|void
name|task198202
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QProgressDialog
name|tst_QProgressDialog
operator|::
name|tst_QProgressDialog
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QProgressDialog
name|tst_QProgressDialog
operator|::
name|~
name|tst_QProgressDialog
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|// Testing get/set functions
end_comment
begin_function
DECL|function|getSetCheck
name|void
name|tst_QProgressDialog
operator|::
name|getSetCheck
parameter_list|()
block|{
name|QProgressDialog
name|obj1
decl_stmt|;
comment|// bool QProgressDialog::autoReset()
comment|// void QProgressDialog::setAutoReset(bool)
name|obj1
operator|.
name|setAutoReset
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|false
argument_list|,
name|obj1
operator|.
name|autoReset
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setAutoReset
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|true
argument_list|,
name|obj1
operator|.
name|autoReset
argument_list|()
argument_list|)
expr_stmt|;
comment|// bool QProgressDialog::autoClose()
comment|// void QProgressDialog::setAutoClose(bool)
name|obj1
operator|.
name|setAutoClose
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|false
argument_list|,
name|obj1
operator|.
name|autoClose
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setAutoClose
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|true
argument_list|,
name|obj1
operator|.
name|autoClose
argument_list|()
argument_list|)
expr_stmt|;
comment|// int QProgressDialog::maximum()
comment|// void QProgressDialog::setMaximum(int)
name|obj1
operator|.
name|setMaximum
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|0
argument_list|,
name|obj1
operator|.
name|maximum
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setMaximum
argument_list|(
name|INT_MIN
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|INT_MIN
argument_list|,
name|obj1
operator|.
name|maximum
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setMaximum
argument_list|(
name|INT_MAX
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|INT_MAX
argument_list|,
name|obj1
operator|.
name|maximum
argument_list|()
argument_list|)
expr_stmt|;
comment|// int QProgressDialog::minimum()
comment|// void QProgressDialog::setMinimum(int)
name|obj1
operator|.
name|setMinimum
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|0
argument_list|,
name|obj1
operator|.
name|minimum
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setMinimum
argument_list|(
name|INT_MIN
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|INT_MIN
argument_list|,
name|obj1
operator|.
name|minimum
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setMinimum
argument_list|(
name|INT_MAX
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|INT_MAX
argument_list|,
name|obj1
operator|.
name|minimum
argument_list|()
argument_list|)
expr_stmt|;
comment|// int QProgressDialog::value()
comment|// void QProgressDialog::setValue(int)
name|obj1
operator|.
name|setMaximum
argument_list|(
name|INT_MAX
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setMinimum
argument_list|(
name|INT_MIN
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setValue
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|0
argument_list|,
name|obj1
operator|.
name|value
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setValue
argument_list|(
name|INT_MIN
operator|+
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|INT_MIN
operator|+
literal|1
argument_list|,
name|obj1
operator|.
name|value
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setValue
argument_list|(
name|INT_MIN
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|INT_MIN
argument_list|,
name|obj1
operator|.
name|value
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setValue
argument_list|(
name|INT_MAX
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|INT_MAX
operator|-
literal|1
argument_list|,
name|obj1
operator|.
name|value
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setValue
argument_list|(
name|INT_MAX
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|INT_MIN
argument_list|,
name|obj1
operator|.
name|value
argument_list|()
argument_list|)
expr_stmt|;
comment|// We set autoReset, the thing is reset
name|obj1
operator|.
name|setAutoReset
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setValue
argument_list|(
name|INT_MAX
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|INT_MAX
argument_list|,
name|obj1
operator|.
name|value
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setAutoReset
argument_list|(
literal|true
argument_list|)
expr_stmt|;
comment|// int QProgressDialog::minimumDuration()
comment|// void QProgressDialog::setMinimumDuration(int)
name|obj1
operator|.
name|setMinimumDuration
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
literal|0
argument_list|,
name|obj1
operator|.
name|minimumDuration
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setMinimumDuration
argument_list|(
name|INT_MIN
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|INT_MIN
argument_list|,
name|obj1
operator|.
name|minimumDuration
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setMinimumDuration
argument_list|(
name|INT_MAX
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|INT_MAX
argument_list|,
name|obj1
operator|.
name|minimumDuration
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|task198202
name|void
name|tst_QProgressDialog
operator|::
name|task198202
parameter_list|()
block|{
comment|//should not crash
name|QProgressDialog
name|dlg
argument_list|(
name|QLatin1String
argument_list|(
literal|"test"
argument_list|)
argument_list|,
name|QLatin1String
argument_list|(
literal|"test"
argument_list|)
argument_list|,
literal|1
argument_list|,
literal|10
argument_list|)
decl_stmt|;
name|dlg
operator|.
name|show
argument_list|()
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|20
argument_list|)
expr_stmt|;
name|int
name|futureHeight
init|=
name|dlg
operator|.
name|sizeHint
argument_list|()
operator|.
name|height
argument_list|()
operator|-
name|qFindChild
argument_list|<
name|QLabel
operator|*
argument_list|>
argument_list|(
operator|&
name|dlg
argument_list|)
operator|->
name|sizeHint
argument_list|()
operator|.
name|height
argument_list|()
decl_stmt|;
name|dlg
operator|.
name|setLabel
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
literal|"QProgressDialog::setBar: Cannot set a null progress bar"
argument_list|)
expr_stmt|;
name|dlg
operator|.
name|setBar
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|qWait
argument_list|(
literal|20
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|dlg
operator|.
name|sizeHint
argument_list|()
operator|.
name|height
argument_list|()
argument_list|,
name|futureHeight
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QProgressDialog
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qprogressdialog.moc"
end_include
end_unit
