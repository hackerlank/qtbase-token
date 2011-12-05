begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_include
include|#
directive|include
file|<QQuaternion>
end_include
begin_class
DECL|class|tst_QQuaternion
class|class
name|tst_QQuaternion
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QQuaternion
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QQuaternion
parameter_list|()
destructor_decl|;
public|public
name|slots
public|:
name|void
name|init
parameter_list|()
function_decl|;
name|void
name|cleanup
parameter_list|()
function_decl|;
private|private
name|slots
private|:
name|void
name|multiply_data
parameter_list|()
function_decl|;
name|void
name|multiply
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QQuaternion
name|tst_QQuaternion
operator|::
name|tst_QQuaternion
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QQuaternion
name|tst_QQuaternion
operator|::
name|~
name|tst_QQuaternion
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|init
name|void
name|tst_QQuaternion
operator|::
name|init
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QQuaternion
operator|::
name|cleanup
parameter_list|()
block|{ }
end_function
begin_function
DECL|function|multiply_data
name|void
name|tst_QQuaternion
operator|::
name|multiply_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|qreal
argument_list|>
argument_list|(
literal|"x1"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|qreal
argument_list|>
argument_list|(
literal|"y1"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|qreal
argument_list|>
argument_list|(
literal|"z1"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|qreal
argument_list|>
argument_list|(
literal|"w1"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|qreal
argument_list|>
argument_list|(
literal|"x2"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|qreal
argument_list|>
argument_list|(
literal|"y2"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|qreal
argument_list|>
argument_list|(
literal|"z2"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|qreal
argument_list|>
argument_list|(
literal|"w2"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"null"
argument_list|)
operator|<<
operator|(
name|qreal
operator|)
literal|0.0f
operator|<<
operator|(
name|qreal
operator|)
literal|0.0f
operator|<<
operator|(
name|qreal
operator|)
literal|0.0f
operator|<<
operator|(
name|qreal
operator|)
literal|0.0f
operator|<<
operator|(
name|qreal
operator|)
literal|0.0f
operator|<<
operator|(
name|qreal
operator|)
literal|0.0f
operator|<<
operator|(
name|qreal
operator|)
literal|0.0f
operator|<<
operator|(
name|qreal
operator|)
literal|0.0f
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"unitvec"
argument_list|)
operator|<<
operator|(
name|qreal
operator|)
literal|1.0f
operator|<<
operator|(
name|qreal
operator|)
literal|0.0f
operator|<<
operator|(
name|qreal
operator|)
literal|0.0f
operator|<<
operator|(
name|qreal
operator|)
literal|1.0f
operator|<<
operator|(
name|qreal
operator|)
literal|0.0f
operator|<<
operator|(
name|qreal
operator|)
literal|1.0f
operator|<<
operator|(
name|qreal
operator|)
literal|0.0f
operator|<<
operator|(
name|qreal
operator|)
literal|1.0f
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"complex"
argument_list|)
operator|<<
operator|(
name|qreal
operator|)
literal|1.0f
operator|<<
operator|(
name|qreal
operator|)
literal|2.0f
operator|<<
operator|(
name|qreal
operator|)
literal|3.0f
operator|<<
operator|(
name|qreal
operator|)
literal|7.0f
operator|<<
operator|(
name|qreal
operator|)
literal|4.0f
operator|<<
operator|(
name|qreal
operator|)
literal|5.0f
operator|<<
operator|(
name|qreal
operator|)
literal|6.0f
operator|<<
operator|(
name|qreal
operator|)
literal|8.0f
expr_stmt|;
block|}
end_function
begin_function
DECL|function|multiply
name|void
name|tst_QQuaternion
operator|::
name|multiply
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|qreal
argument_list|,
name|x1
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|qreal
argument_list|,
name|y1
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|qreal
argument_list|,
name|z1
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|qreal
argument_list|,
name|w1
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|qreal
argument_list|,
name|x2
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|qreal
argument_list|,
name|y2
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|qreal
argument_list|,
name|z2
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|qreal
argument_list|,
name|w2
argument_list|)
expr_stmt|;
name|QQuaternion
name|q1
argument_list|(
name|w1
argument_list|,
name|x1
argument_list|,
name|y1
argument_list|,
name|z1
argument_list|)
decl_stmt|;
name|QQuaternion
name|q2
argument_list|(
name|w2
argument_list|,
name|x2
argument_list|,
name|y2
argument_list|,
name|z2
argument_list|)
decl_stmt|;
name|QBENCHMARK
block|{
name|QQuaternion
name|q3
init|=
name|q1
operator|*
name|q2
decl_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QQuaternion
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qquaternion.moc"
end_include
end_unit
