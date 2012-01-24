begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_comment
comment|// This file contains benchmarks for QRegion functions.
end_comment
begin_include
include|#
directive|include
file|<QDebug>
end_include
begin_include
include|#
directive|include
file|<qtest.h>
end_include
begin_class
DECL|class|tst_qregion
class|class
name|tst_qregion
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|map_data
parameter_list|()
function_decl|;
name|void
name|map
parameter_list|()
function_decl|;
name|void
name|intersects_data
parameter_list|()
function_decl|;
name|void
name|intersects
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|map_data
name|void
name|tst_qregion
operator|::
name|map_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QRegion
argument_list|>
argument_list|(
literal|"region"
argument_list|)
expr_stmt|;
block|{
name|QRegion
name|region
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"single rect"
argument_list|)
operator|<<
name|region
expr_stmt|;
block|}
block|{
name|QRegion
name|region
decl_stmt|;
name|region
operator|=
name|region
operator|.
name|united
argument_list|(
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
expr_stmt|;
name|region
operator|=
name|region
operator|.
name|united
argument_list|(
name|QRect
argument_list|(
literal|120
argument_list|,
literal|20
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"two rects"
argument_list|)
operator|<<
name|region
expr_stmt|;
block|}
block|{
name|QRegion
name|region
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|,
name|QRegion
operator|::
name|Ellipse
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"ellipse"
argument_list|)
operator|<<
name|region
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|map
name|void
name|tst_qregion
operator|::
name|map
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QRegion
argument_list|,
name|region
argument_list|)
expr_stmt|;
name|QTransform
name|transform
decl_stmt|;
name|transform
operator|.
name|rotate
argument_list|(
literal|30
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|transform
operator|.
name|map
argument_list|(
name|region
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|intersects_data
name|void
name|tst_qregion
operator|::
name|intersects_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|QRegion
argument_list|>
argument_list|(
literal|"region"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QRect
argument_list|>
argument_list|(
literal|"rect"
argument_list|)
expr_stmt|;
name|QRegion
name|region
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
decl_stmt|;
name|QRegion
name|complexRegion
decl_stmt|;
name|complexRegion
operator|=
name|complexRegion
operator|.
name|united
argument_list|(
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
expr_stmt|;
name|complexRegion
operator|=
name|complexRegion
operator|.
name|united
argument_list|(
name|QRect
argument_list|(
literal|120
argument_list|,
literal|20
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|)
expr_stmt|;
block|{
name|QRect
name|rect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"same -- simple"
argument_list|)
operator|<<
name|region
operator|<<
name|rect
expr_stmt|;
block|}
block|{
name|QRect
name|rect
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"inside -- simple"
argument_list|)
operator|<<
name|region
operator|<<
name|rect
expr_stmt|;
block|}
block|{
name|QRect
name|rect
argument_list|(
literal|110
argument_list|,
literal|110
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"outside -- simple"
argument_list|)
operator|<<
name|region
operator|<<
name|rect
expr_stmt|;
block|}
block|{
name|QRect
name|rect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"same -- complex"
argument_list|)
operator|<<
name|complexRegion
operator|<<
name|rect
expr_stmt|;
block|}
block|{
name|QRect
name|rect
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"inside -- complex"
argument_list|)
operator|<<
name|complexRegion
operator|<<
name|rect
expr_stmt|;
block|}
block|{
name|QRect
name|rect
argument_list|(
literal|110
argument_list|,
literal|110
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"outside -- complex"
argument_list|)
operator|<<
name|complexRegion
operator|<<
name|rect
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|intersects
name|void
name|tst_qregion
operator|::
name|intersects
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QRegion
argument_list|,
name|region
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QRect
argument_list|,
name|rect
argument_list|)
expr_stmt|;
name|QBENCHMARK
block|{
name|region
operator|.
name|intersects
argument_list|(
name|rect
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_qregion
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"main.moc"
end_include
end_unit
