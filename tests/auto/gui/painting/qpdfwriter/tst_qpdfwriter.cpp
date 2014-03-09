begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<QtGlobal>
end_include
begin_include
include|#
directive|include
file|<QtAlgorithms>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPageLayout>
end_include
begin_include
include|#
directive|include
file|<QtGui/QPdfWriter>
end_include
begin_class
DECL|class|tst_QPdfWriter
class|class
name|tst_QPdfWriter
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|basics
parameter_list|()
function_decl|;
name|void
name|testPageMetrics_data
parameter_list|()
function_decl|;
name|void
name|testPageMetrics
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|basics
name|void
name|tst_QPdfWriter
operator|::
name|basics
parameter_list|()
block|{
name|QTemporaryFile
name|file
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|open
argument_list|()
condition|)
name|QSKIP
argument_list|(
literal|"Couldn't open temp file!"
argument_list|)
expr_stmt|;
name|QPdfWriter
name|writer
argument_list|(
name|file
operator|.
name|fileName
argument_list|()
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|title
argument_list|()
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|writer
operator|.
name|setTitle
argument_list|(
name|QString
argument_list|(
literal|"Test Title"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|title
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"Test Title"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|creator
argument_list|()
argument_list|,
name|QString
argument_list|()
argument_list|)
expr_stmt|;
name|writer
operator|.
name|setCreator
argument_list|(
name|QString
argument_list|(
literal|"Test Creator"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|creator
argument_list|()
argument_list|,
name|QString
argument_list|(
literal|"Test Creator"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|resolution
argument_list|()
argument_list|,
literal|1200
argument_list|)
expr_stmt|;
name|writer
operator|.
name|setResolution
argument_list|(
literal|600
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|resolution
argument_list|()
argument_list|,
literal|600
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageLayout
argument_list|()
operator|.
name|pageSize
argument_list|()
operator|.
name|id
argument_list|()
argument_list|,
name|QPageSize
operator|::
name|A4
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageSize
argument_list|()
argument_list|,
name|QPdfWriter
operator|::
name|A4
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageSizeMM
argument_list|()
argument_list|,
name|QSizeF
argument_list|(
literal|210
argument_list|,
literal|297
argument_list|)
argument_list|)
expr_stmt|;
name|writer
operator|.
name|setPageSize
argument_list|(
name|QPageSize
argument_list|(
name|QPageSize
operator|::
name|A5
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageLayout
argument_list|()
operator|.
name|pageSize
argument_list|()
operator|.
name|id
argument_list|()
argument_list|,
name|QPageSize
operator|::
name|A5
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageSize
argument_list|()
argument_list|,
name|QPdfWriter
operator|::
name|A5
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageSizeMM
argument_list|()
argument_list|,
name|QSizeF
argument_list|(
literal|148
argument_list|,
literal|210
argument_list|)
argument_list|)
expr_stmt|;
name|writer
operator|.
name|setPageSize
argument_list|(
name|QPdfWriter
operator|::
name|A3
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageLayout
argument_list|()
operator|.
name|pageSize
argument_list|()
operator|.
name|id
argument_list|()
argument_list|,
name|QPageSize
operator|::
name|A3
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageSize
argument_list|()
argument_list|,
name|QPdfWriter
operator|::
name|A3
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageSizeMM
argument_list|()
argument_list|,
name|QSizeF
argument_list|(
literal|297
argument_list|,
literal|420
argument_list|)
argument_list|)
expr_stmt|;
name|writer
operator|.
name|setPageSizeMM
argument_list|(
name|QSize
argument_list|(
literal|210
argument_list|,
literal|297
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageLayout
argument_list|()
operator|.
name|pageSize
argument_list|()
operator|.
name|id
argument_list|()
argument_list|,
name|QPageSize
operator|::
name|A4
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageSize
argument_list|()
argument_list|,
name|QPdfWriter
operator|::
name|A4
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageSizeMM
argument_list|()
argument_list|,
name|QSizeF
argument_list|(
literal|210
argument_list|,
literal|297
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageLayout
argument_list|()
operator|.
name|orientation
argument_list|()
argument_list|,
name|QPageLayout
operator|::
name|Portrait
argument_list|)
expr_stmt|;
name|writer
operator|.
name|setPageOrientation
argument_list|(
name|QPageLayout
operator|::
name|Landscape
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageLayout
argument_list|()
operator|.
name|orientation
argument_list|()
argument_list|,
name|QPageLayout
operator|::
name|Landscape
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageSizeMM
argument_list|()
argument_list|,
name|QSizeF
argument_list|(
literal|210
argument_list|,
literal|297
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageLayout
argument_list|()
operator|.
name|margins
argument_list|()
argument_list|,
name|QMarginsF
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|,
literal|10
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageLayout
argument_list|()
operator|.
name|units
argument_list|()
argument_list|,
name|QPageLayout
operator|::
name|Point
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|margins
argument_list|()
operator|.
name|left
argument_list|,
literal|3.53
argument_list|)
expr_stmt|;
comment|// mm
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|margins
argument_list|()
operator|.
name|right
argument_list|,
literal|3.53
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|margins
argument_list|()
operator|.
name|top
argument_list|,
literal|3.53
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|margins
argument_list|()
operator|.
name|bottom
argument_list|,
literal|3.53
argument_list|)
expr_stmt|;
name|writer
operator|.
name|setPageMargins
argument_list|(
name|QMarginsF
argument_list|(
literal|20
argument_list|,
literal|20
argument_list|,
literal|20
argument_list|,
literal|20
argument_list|)
argument_list|,
name|QPageLayout
operator|::
name|Millimeter
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageLayout
argument_list|()
operator|.
name|margins
argument_list|()
argument_list|,
name|QMarginsF
argument_list|(
literal|20
argument_list|,
literal|20
argument_list|,
literal|20
argument_list|,
literal|20
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageLayout
argument_list|()
operator|.
name|units
argument_list|()
argument_list|,
name|QPageLayout
operator|::
name|Millimeter
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|margins
argument_list|()
operator|.
name|left
argument_list|,
literal|20.0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|margins
argument_list|()
operator|.
name|right
argument_list|,
literal|20.0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|margins
argument_list|()
operator|.
name|top
argument_list|,
literal|20.0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|margins
argument_list|()
operator|.
name|bottom
argument_list|,
literal|20.0
argument_list|)
expr_stmt|;
name|QPdfWriter
operator|::
name|Margins
name|margins
init|=
block|{
literal|50
block|,
literal|50
block|,
literal|50
block|,
literal|50
block|}
decl_stmt|;
name|writer
operator|.
name|setMargins
argument_list|(
name|margins
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageLayout
argument_list|()
operator|.
name|margins
argument_list|()
argument_list|,
name|QMarginsF
argument_list|(
literal|50
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|,
literal|50
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageLayout
argument_list|()
operator|.
name|units
argument_list|()
argument_list|,
name|QPageLayout
operator|::
name|Millimeter
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|margins
argument_list|()
operator|.
name|left
argument_list|,
literal|50.0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|margins
argument_list|()
operator|.
name|right
argument_list|,
literal|50.0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|margins
argument_list|()
operator|.
name|top
argument_list|,
literal|50.0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|margins
argument_list|()
operator|.
name|bottom
argument_list|,
literal|50.0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageLayout
argument_list|()
operator|.
name|fullRect
argument_list|(
name|QPageLayout
operator|::
name|Millimeter
argument_list|)
argument_list|,
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|297
argument_list|,
literal|210
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageLayout
argument_list|()
operator|.
name|paintRect
argument_list|(
name|QPageLayout
operator|::
name|Millimeter
argument_list|)
argument_list|,
name|QRectF
argument_list|(
literal|50
argument_list|,
literal|50
argument_list|,
literal|197
argument_list|,
literal|110
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// Test the old page metrics methods, see also QPrinter tests for the same.
end_comment
begin_function
DECL|function|testPageMetrics_data
name|void
name|tst_QPdfWriter
operator|::
name|testPageMetrics_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"pageSize"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|qreal
argument_list|>
argument_list|(
literal|"widthMMf"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|qreal
argument_list|>
argument_list|(
literal|"heightMMf"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|bool
argument_list|>
argument_list|(
literal|"setMargins"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|qreal
argument_list|>
argument_list|(
literal|"leftMMf"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|qreal
argument_list|>
argument_list|(
literal|"rightMMf"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|qreal
argument_list|>
argument_list|(
literal|"topMMf"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|qreal
argument_list|>
argument_list|(
literal|"bottomMMf"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"A4"
argument_list|)
operator|<<
name|int
argument_list|(
name|QPdfWriter
operator|::
name|A4
argument_list|)
operator|<<
literal|210.0
operator|<<
literal|297.0
operator|<<
literal|false
operator|<<
literal|3.53
operator|<<
literal|3.53
operator|<<
literal|3.53
operator|<<
literal|3.53
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"A4 Margins"
argument_list|)
operator|<<
name|int
argument_list|(
name|QPdfWriter
operator|::
name|A4
argument_list|)
operator|<<
literal|210.0
operator|<<
literal|297.0
operator|<<
literal|true
operator|<<
literal|20.0
operator|<<
literal|30.0
operator|<<
literal|40.0
operator|<<
literal|50.0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Portrait"
argument_list|)
operator|<<
operator|-
literal|1
operator|<<
literal|345.0
operator|<<
literal|678.0
operator|<<
literal|false
operator|<<
literal|3.53
operator|<<
literal|3.53
operator|<<
literal|3.53
operator|<<
literal|3.53
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Portrait Margins"
argument_list|)
operator|<<
operator|-
literal|1
operator|<<
literal|345.0
operator|<<
literal|678.0
operator|<<
literal|true
operator|<<
literal|20.0
operator|<<
literal|30.0
operator|<<
literal|40.0
operator|<<
literal|50.0
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Landscape"
argument_list|)
operator|<<
operator|-
literal|1
operator|<<
literal|678.0
operator|<<
literal|345.0
operator|<<
literal|false
operator|<<
literal|3.53
operator|<<
literal|3.53
operator|<<
literal|3.53
operator|<<
literal|3.53
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"Landscape Margins"
argument_list|)
operator|<<
operator|-
literal|1
operator|<<
literal|678.0
operator|<<
literal|345.0
operator|<<
literal|true
operator|<<
literal|20.0
operator|<<
literal|30.0
operator|<<
literal|40.0
operator|<<
literal|50.0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|testPageMetrics
name|void
name|tst_QPdfWriter
operator|::
name|testPageMetrics
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|int
argument_list|,
name|pageSize
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|qreal
argument_list|,
name|widthMMf
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|qreal
argument_list|,
name|heightMMf
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|bool
argument_list|,
name|setMargins
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|qreal
argument_list|,
name|leftMMf
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|qreal
argument_list|,
name|rightMMf
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|qreal
argument_list|,
name|topMMf
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|qreal
argument_list|,
name|bottomMMf
argument_list|)
expr_stmt|;
name|QSizeF
name|sizeMMf
init|=
name|QSizeF
argument_list|(
name|widthMMf
argument_list|,
name|heightMMf
argument_list|)
decl_stmt|;
name|QTemporaryFile
name|file
decl_stmt|;
if|if
condition|(
operator|!
name|file
operator|.
name|open
argument_list|()
condition|)
name|QSKIP
argument_list|(
literal|"Couldn't open temp file!"
argument_list|)
expr_stmt|;
name|QPdfWriter
name|writer
argument_list|(
name|file
operator|.
name|fileName
argument_list|()
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageLayout
argument_list|()
operator|.
name|orientation
argument_list|()
argument_list|,
name|QPageLayout
operator|::
name|Portrait
argument_list|)
expr_stmt|;
if|if
condition|(
name|setMargins
condition|)
block|{
comment|// Setup the given margins
name|QPdfWriter
operator|::
name|Margins
name|margins
decl_stmt|;
name|margins
operator|.
name|left
operator|=
name|leftMMf
expr_stmt|;
name|margins
operator|.
name|right
operator|=
name|rightMMf
expr_stmt|;
name|margins
operator|.
name|top
operator|=
name|topMMf
expr_stmt|;
name|margins
operator|.
name|bottom
operator|=
name|bottomMMf
expr_stmt|;
name|writer
operator|.
name|setMargins
argument_list|(
name|margins
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|margins
argument_list|()
operator|.
name|left
argument_list|,
name|leftMMf
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|margins
argument_list|()
operator|.
name|right
argument_list|,
name|rightMMf
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|margins
argument_list|()
operator|.
name|top
argument_list|,
name|topMMf
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|margins
argument_list|()
operator|.
name|bottom
argument_list|,
name|bottomMMf
argument_list|)
expr_stmt|;
block|}
comment|// Set the given size, in Portrait mode
if|if
condition|(
name|pageSize
operator|<
literal|0
condition|)
block|{
name|writer
operator|.
name|setPageSizeMM
argument_list|(
name|sizeMMf
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageSize
argument_list|()
argument_list|,
name|QPdfWriter
operator|::
name|Custom
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageLayout
argument_list|()
operator|.
name|pageSize
argument_list|()
operator|.
name|id
argument_list|()
argument_list|,
name|QPageSize
operator|::
name|Custom
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|writer
operator|.
name|setPageSize
argument_list|(
name|QPdfWriter
operator|::
name|PageSize
argument_list|(
name|pageSize
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageSize
argument_list|()
argument_list|,
name|QPdfWriter
operator|::
name|PageSize
argument_list|(
name|pageSize
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageLayout
argument_list|()
operator|.
name|pageSize
argument_list|()
operator|.
name|id
argument_list|()
argument_list|,
name|QPageSize
operator|::
name|PageSizeId
argument_list|(
name|pageSize
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageLayout
argument_list|()
operator|.
name|orientation
argument_list|()
argument_list|,
name|QPageLayout
operator|::
name|Portrait
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|margins
argument_list|()
operator|.
name|left
argument_list|,
name|leftMMf
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|margins
argument_list|()
operator|.
name|right
argument_list|,
name|rightMMf
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|margins
argument_list|()
operator|.
name|top
argument_list|,
name|topMMf
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|margins
argument_list|()
operator|.
name|bottom
argument_list|,
name|bottomMMf
argument_list|)
expr_stmt|;
comment|// QPagedPaintDevice::pageSizeMM() always returns Portrait
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageSizeMM
argument_list|()
argument_list|,
name|sizeMMf
argument_list|)
expr_stmt|;
comment|// QPagedPaintDevice::widthMM() and heightMM() are paint metrics and always return set orientation
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|widthMM
argument_list|()
argument_list|,
name|qRound
argument_list|(
name|widthMMf
operator|-
name|leftMMf
operator|-
name|rightMMf
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|heightMM
argument_list|()
argument_list|,
name|qRound
argument_list|(
name|heightMMf
operator|-
name|topMMf
operator|-
name|bottomMMf
argument_list|)
argument_list|)
expr_stmt|;
comment|// Now switch to Landscape mode, size should be unchanged, but rect and metrics should change
name|writer
operator|.
name|setPageOrientation
argument_list|(
name|QPageLayout
operator|::
name|Landscape
argument_list|)
expr_stmt|;
if|if
condition|(
name|pageSize
operator|<
literal|0
condition|)
block|{
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageSize
argument_list|()
argument_list|,
name|QPdfWriter
operator|::
name|Custom
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageLayout
argument_list|()
operator|.
name|pageSize
argument_list|()
operator|.
name|id
argument_list|()
argument_list|,
name|QPageSize
operator|::
name|Custom
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageSize
argument_list|()
argument_list|,
name|QPdfWriter
operator|::
name|PageSize
argument_list|(
name|pageSize
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageLayout
argument_list|()
operator|.
name|pageSize
argument_list|()
operator|.
name|id
argument_list|()
argument_list|,
name|QPageSize
operator|::
name|PageSizeId
argument_list|(
name|pageSize
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageLayout
argument_list|()
operator|.
name|orientation
argument_list|()
argument_list|,
name|QPageLayout
operator|::
name|Landscape
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|margins
argument_list|()
operator|.
name|left
argument_list|,
name|leftMMf
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|margins
argument_list|()
operator|.
name|right
argument_list|,
name|rightMMf
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|margins
argument_list|()
operator|.
name|top
argument_list|,
name|topMMf
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|margins
argument_list|()
operator|.
name|bottom
argument_list|,
name|bottomMMf
argument_list|)
expr_stmt|;
comment|// QPagedPaintDevice::pageSizeMM() always returns Portrait
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageSizeMM
argument_list|()
argument_list|,
name|sizeMMf
argument_list|)
expr_stmt|;
comment|// QPagedPaintDevice::widthMM() and heightMM() are paint metrics and always return set orientation
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|widthMM
argument_list|()
argument_list|,
name|qRound
argument_list|(
name|heightMMf
operator|-
name|leftMMf
operator|-
name|rightMMf
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|heightMM
argument_list|()
argument_list|,
name|qRound
argument_list|(
name|widthMMf
operator|-
name|topMMf
operator|-
name|bottomMMf
argument_list|)
argument_list|)
expr_stmt|;
comment|// QPdfWriter::fullRect() always returns set orientation
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageLayout
argument_list|()
operator|.
name|fullRect
argument_list|(
name|QPageLayout
operator|::
name|Millimeter
argument_list|)
argument_list|,
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|heightMMf
argument_list|,
name|widthMMf
argument_list|)
argument_list|)
expr_stmt|;
comment|// QPdfWriter::paintRect() always returns set orientation
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageLayout
argument_list|()
operator|.
name|paintRect
argument_list|(
name|QPageLayout
operator|::
name|Millimeter
argument_list|)
argument_list|,
name|QRectF
argument_list|(
name|leftMMf
argument_list|,
name|topMMf
argument_list|,
name|heightMMf
operator|-
name|leftMMf
operator|-
name|rightMMf
argument_list|,
name|widthMMf
operator|-
name|topMMf
operator|-
name|bottomMMf
argument_list|)
argument_list|)
expr_stmt|;
comment|// Now while in Landscape mode, set the size again, results should be the same
if|if
condition|(
name|pageSize
operator|<
literal|0
condition|)
block|{
name|writer
operator|.
name|setPageSizeMM
argument_list|(
name|sizeMMf
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageSize
argument_list|()
argument_list|,
name|QPdfWriter
operator|::
name|Custom
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageLayout
argument_list|()
operator|.
name|pageSize
argument_list|()
operator|.
name|id
argument_list|()
argument_list|,
name|QPageSize
operator|::
name|Custom
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|writer
operator|.
name|setPageSize
argument_list|(
name|QPdfWriter
operator|::
name|PageSize
argument_list|(
name|pageSize
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageSize
argument_list|()
argument_list|,
name|QPdfWriter
operator|::
name|PageSize
argument_list|(
name|pageSize
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageLayout
argument_list|()
operator|.
name|pageSize
argument_list|()
operator|.
name|id
argument_list|()
argument_list|,
name|QPageSize
operator|::
name|PageSizeId
argument_list|(
name|pageSize
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageLayout
argument_list|()
operator|.
name|orientation
argument_list|()
argument_list|,
name|QPageLayout
operator|::
name|Landscape
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|margins
argument_list|()
operator|.
name|left
argument_list|,
name|leftMMf
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|margins
argument_list|()
operator|.
name|right
argument_list|,
name|rightMMf
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|margins
argument_list|()
operator|.
name|top
argument_list|,
name|topMMf
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|margins
argument_list|()
operator|.
name|bottom
argument_list|,
name|bottomMMf
argument_list|)
expr_stmt|;
comment|// QPagedPaintDevice::pageSizeMM() always returns Portrait
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageSizeMM
argument_list|()
argument_list|,
name|sizeMMf
argument_list|)
expr_stmt|;
comment|// QPagedPaintDevice::widthMM() and heightMM() are paint metrics and always return set orientation
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|widthMM
argument_list|()
argument_list|,
name|qRound
argument_list|(
name|heightMMf
operator|-
name|leftMMf
operator|-
name|rightMMf
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|heightMM
argument_list|()
argument_list|,
name|qRound
argument_list|(
name|widthMMf
operator|-
name|topMMf
operator|-
name|bottomMMf
argument_list|)
argument_list|)
expr_stmt|;
comment|// QPdfWriter::fullRect() always returns set orientation
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageLayout
argument_list|()
operator|.
name|fullRect
argument_list|(
name|QPageLayout
operator|::
name|Millimeter
argument_list|)
argument_list|,
name|QRectF
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|heightMMf
argument_list|,
name|widthMMf
argument_list|)
argument_list|)
expr_stmt|;
comment|// QPdfWriter::paintRect() always returns set orientation
name|QCOMPARE
argument_list|(
name|writer
operator|.
name|pageLayout
argument_list|()
operator|.
name|paintRect
argument_list|(
name|QPageLayout
operator|::
name|Millimeter
argument_list|)
argument_list|,
name|QRectF
argument_list|(
name|leftMMf
argument_list|,
name|topMMf
argument_list|,
name|heightMMf
operator|-
name|leftMMf
operator|-
name|rightMMf
argument_list|,
name|widthMMf
operator|-
name|topMMf
operator|-
name|bottomMMf
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QPdfWriter
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qpdfwriter.moc"
end_include
end_unit