begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtCore/qvariantanimation.h>
end_include
begin_include
include|#
directive|include
file|<QtTest>
end_include
begin_class
DECL|class|tst_QVariantAnimation
class|class
name|tst_QVariantAnimation
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|construction
parameter_list|()
function_decl|;
name|void
name|destruction
parameter_list|()
function_decl|;
name|void
name|currentValue
parameter_list|()
function_decl|;
name|void
name|easingCurve
parameter_list|()
function_decl|;
name|void
name|startValue
parameter_list|()
function_decl|;
name|void
name|endValue
parameter_list|()
function_decl|;
name|void
name|keyValueAt
parameter_list|()
function_decl|;
name|void
name|keyValues
parameter_list|()
function_decl|;
name|void
name|duration
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_class
DECL|class|TestableQVariantAnimation
class|class
name|TestableQVariantAnimation
super|:
specifier|public
name|QVariantAnimation
block|{
name|Q_OBJECT
public|public:
DECL|function|updateCurrentValue
name|void
name|updateCurrentValue
parameter_list|(
specifier|const
name|QVariant
modifier|&
parameter_list|)
block|{}
block|}
class|;
end_class
begin_function
DECL|function|construction
name|void
name|tst_QVariantAnimation
operator|::
name|construction
parameter_list|()
block|{
name|TestableQVariantAnimation
name|anim
decl_stmt|;
block|}
end_function
begin_function
DECL|function|destruction
name|void
name|tst_QVariantAnimation
operator|::
name|destruction
parameter_list|()
block|{
name|TestableQVariantAnimation
modifier|*
name|anim
init|=
operator|new
name|TestableQVariantAnimation
decl_stmt|;
operator|delete
name|anim
expr_stmt|;
block|}
end_function
begin_function
DECL|function|currentValue
name|void
name|tst_QVariantAnimation
operator|::
name|currentValue
parameter_list|()
block|{
name|TestableQVariantAnimation
name|anim
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|anim
operator|.
name|currentValue
argument_list|()
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|easingCurve
name|void
name|tst_QVariantAnimation
operator|::
name|easingCurve
parameter_list|()
block|{
name|TestableQVariantAnimation
name|anim
decl_stmt|;
name|QVERIFY
argument_list|(
name|anim
operator|.
name|easingCurve
argument_list|()
operator|==
name|QEasingCurve
operator|::
name|Linear
argument_list|)
expr_stmt|;
name|anim
operator|.
name|setEasingCurve
argument_list|(
name|QEasingCurve
operator|::
name|InQuad
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|anim
operator|.
name|easingCurve
argument_list|()
operator|==
name|QEasingCurve
operator|::
name|InQuad
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|endValue
name|void
name|tst_QVariantAnimation
operator|::
name|endValue
parameter_list|()
block|{
name|TestableQVariantAnimation
name|anim
decl_stmt|;
name|anim
operator|.
name|setEndValue
argument_list|(
name|QVariant
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|anim
operator|.
name|endValue
argument_list|()
operator|.
name|toInt
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|startValue
name|void
name|tst_QVariantAnimation
operator|::
name|startValue
parameter_list|()
block|{
name|TestableQVariantAnimation
name|anim
decl_stmt|;
name|anim
operator|.
name|setStartValue
argument_list|(
name|QVariant
argument_list|(
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|anim
operator|.
name|startValue
argument_list|()
operator|.
name|toInt
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|anim
operator|.
name|setStartValue
argument_list|(
name|QVariant
argument_list|(
operator|-
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|anim
operator|.
name|startValue
argument_list|()
operator|.
name|toInt
argument_list|()
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|keyValueAt
name|void
name|tst_QVariantAnimation
operator|::
name|keyValueAt
parameter_list|()
block|{
name|TestableQVariantAnimation
name|anim
decl_stmt|;
name|int
name|i
init|=
literal|0
decl_stmt|;
for|for
control|(
name|qreal
name|r
init|=
literal|0.0
init|;
name|r
operator|<
literal|1.0
condition|;
name|r
operator|+=
literal|0.1
control|)
block|{
name|anim
operator|.
name|setKeyValueAt
argument_list|(
literal|0.1
argument_list|,
operator|++
name|i
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|anim
operator|.
name|keyValueAt
argument_list|(
literal|0.1
argument_list|)
operator|.
name|toInt
argument_list|()
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|keyValues
name|void
name|tst_QVariantAnimation
operator|::
name|keyValues
parameter_list|()
block|{
name|TestableQVariantAnimation
name|anim
decl_stmt|;
name|QVariantAnimation
operator|::
name|KeyValues
name|values
decl_stmt|;
name|int
name|i
init|=
literal|0
decl_stmt|;
for|for
control|(
name|qreal
name|r
init|=
literal|0.0
init|;
name|r
operator|<
literal|1.0
condition|;
name|r
operator|+=
literal|0.1
control|)
block|{
name|values
operator|.
name|append
argument_list|(
name|QVariantAnimation
operator|::
name|KeyValue
argument_list|(
name|r
argument_list|,
name|i
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|anim
operator|.
name|setKeyValues
argument_list|(
name|values
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|anim
operator|.
name|keyValues
argument_list|()
argument_list|,
name|values
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|duration
name|void
name|tst_QVariantAnimation
operator|::
name|duration
parameter_list|()
block|{
name|TestableQVariantAnimation
name|anim
decl_stmt|;
name|QCOMPARE
argument_list|(
name|anim
operator|.
name|duration
argument_list|()
argument_list|,
literal|250
argument_list|)
expr_stmt|;
name|anim
operator|.
name|setDuration
argument_list|(
literal|500
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|anim
operator|.
name|duration
argument_list|()
argument_list|,
literal|500
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|ignoreMessage
argument_list|(
name|QtWarningMsg
argument_list|,
literal|"QVariantAnimation::setDuration: cannot set a negative duration"
argument_list|)
expr_stmt|;
name|anim
operator|.
name|setDuration
argument_list|(
operator|-
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|anim
operator|.
name|duration
argument_list|()
argument_list|,
literal|500
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QVariantAnimation
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qvariantanimation.moc"
end_include
end_unit
