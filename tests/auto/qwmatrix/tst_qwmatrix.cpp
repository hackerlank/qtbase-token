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
file|<qmatrix.h>
end_include
begin_include
include|#
directive|include
file|<math.h>
end_include
begin_include
include|#
directive|include
file|<qpolygon.h>
end_include
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QRect
argument_list|)
end_macro
begin_comment
comment|//TESTED_CLASS=
end_comment
begin_comment
comment|//TESTED_FILES=gui/painting/qmatrix.h gui/painting/qmatrix.cpp
end_comment
begin_class
DECL|class|tst_QWMatrix
class|class
name|tst_QWMatrix
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QWMatrix
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QWMatrix
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
name|mapRect_data
parameter_list|()
function_decl|;
name|void
name|operator_star_qrect_data
parameter_list|()
function_decl|;
name|void
name|mapToPolygon_data
parameter_list|()
function_decl|;
name|void
name|mapRect
parameter_list|()
function_decl|;
name|void
name|operator_star_qrect
parameter_list|()
function_decl|;
name|void
name|operator_star_qwmatrix
parameter_list|()
function_decl|;
name|void
name|assignments
parameter_list|()
function_decl|;
name|void
name|mapToPolygon
parameter_list|()
function_decl|;
name|void
name|translate
parameter_list|()
function_decl|;
name|void
name|scale
parameter_list|()
function_decl|;
name|void
name|mapPolygon
parameter_list|()
function_decl|;
private|private:
name|void
name|mapping_data
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QMatrix
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QPolygon
argument_list|)
end_macro
begin_constructor
DECL|function|tst_QWMatrix
name|tst_QWMatrix
operator|::
name|tst_QWMatrix
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QWMatrix
name|tst_QWMatrix
operator|::
name|~
name|tst_QWMatrix
parameter_list|()
block|{ }
end_destructor
begin_function
DECL|function|init
name|void
name|tst_QWMatrix
operator|::
name|init
parameter_list|()
block|{
comment|// No initialisation is required
block|}
end_function
begin_function
DECL|function|cleanup
name|void
name|tst_QWMatrix
operator|::
name|cleanup
parameter_list|()
block|{
comment|// No cleanup is required.
block|}
end_function
begin_function
DECL|function|mapRect_data
name|void
name|tst_QWMatrix
operator|::
name|mapRect_data
parameter_list|()
block|{
name|mapping_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|operator_star_qrect_data
name|void
name|tst_QWMatrix
operator|::
name|operator_star_qrect_data
parameter_list|()
block|{
name|mapping_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mapToPolygon_data
name|void
name|tst_QWMatrix
operator|::
name|mapToPolygon_data
parameter_list|()
block|{
name|mapping_data
argument_list|()
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mapping_data
name|void
name|tst_QWMatrix
operator|::
name|mapping_data
parameter_list|()
block|{
comment|//create the testtable instance and define the elements
name|QTest
operator|::
name|addColumn
argument_list|<
name|QMatrix
argument_list|>
argument_list|(
literal|"matrix"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QRect
argument_list|>
argument_list|(
literal|"src"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|QPolygon
argument_list|>
argument_list|(
literal|"res"
argument_list|)
expr_stmt|;
comment|//next we fill it with data
comment|// identity
name|QTest
operator|::
name|newRow
argument_list|(
literal|"identity"
argument_list|)
operator|<<
name|QMatrix
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
name|QRect
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
operator|<<
name|QPolygon
argument_list|(
name|QRect
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
argument_list|)
expr_stmt|;
comment|// scaling
name|QTest
operator|::
name|newRow
argument_list|(
literal|"scale 0"
argument_list|)
operator|<<
name|QMatrix
argument_list|(
literal|2
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|2
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
name|QRect
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
operator|<<
name|QPolygon
argument_list|(
name|QRect
argument_list|(
literal|20
argument_list|,
literal|40
argument_list|,
literal|60
argument_list|,
literal|80
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"scale 1"
argument_list|)
operator|<<
name|QMatrix
argument_list|(
literal|10
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|10
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
name|QRect
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
operator|<<
name|QPolygon
argument_list|(
name|QRect
argument_list|(
literal|100
argument_list|,
literal|200
argument_list|,
literal|300
argument_list|,
literal|400
argument_list|)
argument_list|)
expr_stmt|;
comment|// mirroring
name|QTest
operator|::
name|newRow
argument_list|(
literal|"mirror 0"
argument_list|)
operator|<<
name|QMatrix
argument_list|(
operator|-
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
name|QRect
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
operator|<<
name|QPolygon
argument_list|(
name|QRect
argument_list|(
operator|-
literal|40
argument_list|,
literal|20
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"mirror 1"
argument_list|)
operator|<<
name|QMatrix
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|-
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
name|QRect
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
operator|<<
name|QPolygon
argument_list|(
name|QRect
argument_list|(
literal|10
argument_list|,
operator|-
literal|60
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"mirror 2"
argument_list|)
operator|<<
name|QMatrix
argument_list|(
operator|-
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|-
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
name|QRect
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
operator|<<
name|QPolygon
argument_list|(
name|QRect
argument_list|(
operator|-
literal|40
argument_list|,
operator|-
literal|60
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"mirror 3"
argument_list|)
operator|<<
name|QMatrix
argument_list|(
operator|-
literal|2
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|-
literal|2
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
name|QRect
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
operator|<<
name|QPolygon
argument_list|(
name|QRect
argument_list|(
operator|-
literal|80
argument_list|,
operator|-
literal|120
argument_list|,
literal|60
argument_list|,
literal|80
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"mirror 4"
argument_list|)
operator|<<
name|QMatrix
argument_list|(
operator|-
literal|10
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|-
literal|10
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
name|QRect
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
operator|<<
name|QPolygon
argument_list|(
name|QRect
argument_list|(
operator|-
literal|400
argument_list|,
operator|-
literal|600
argument_list|,
literal|300
argument_list|,
literal|400
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"mirror 5"
argument_list|)
operator|<<
name|QMatrix
argument_list|(
operator|-
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
operator|<<
name|QPolygon
argument_list|(
name|QRect
argument_list|(
operator|-
literal|30
argument_list|,
literal|0
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"mirror 6"
argument_list|)
operator|<<
name|QMatrix
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|-
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
operator|<<
name|QPolygon
argument_list|(
name|QRect
argument_list|(
literal|0
argument_list|,
operator|-
literal|40
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"mirror 7"
argument_list|)
operator|<<
name|QMatrix
argument_list|(
operator|-
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|-
literal|1
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
operator|<<
name|QPolygon
argument_list|(
name|QRect
argument_list|(
operator|-
literal|30
argument_list|,
operator|-
literal|40
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"mirror 8"
argument_list|)
operator|<<
name|QMatrix
argument_list|(
operator|-
literal|2
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|-
literal|2
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
operator|<<
name|QPolygon
argument_list|(
name|QRect
argument_list|(
operator|-
literal|60
argument_list|,
operator|-
literal|80
argument_list|,
literal|60
argument_list|,
literal|80
argument_list|)
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"mirror 9"
argument_list|)
operator|<<
name|QMatrix
argument_list|(
operator|-
literal|10
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
operator|-
literal|10
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
operator|<<
name|QPolygon
argument_list|(
name|QRect
argument_list|(
operator|-
literal|300
argument_list|,
operator|-
literal|400
argument_list|,
literal|300
argument_list|,
literal|400
argument_list|)
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|Q_OS_WINCE
argument_list|)
DECL|macro|M_PI
define|#
directive|define
name|M_PI
value|3.14159265897932384626433832795f
endif|#
directive|endif
comment|// rotations
name|float
name|deg
init|=
literal|0.
decl_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"rot 0 a"
argument_list|)
operator|<<
name|QMatrix
argument_list|(
name|cos
argument_list|(
name|M_PI
operator|*
name|deg
operator|/
literal|180.
argument_list|)
argument_list|,
operator|-
name|sin
argument_list|(
name|M_PI
operator|*
name|deg
operator|/
literal|180.
argument_list|)
argument_list|,
name|sin
argument_list|(
name|M_PI
operator|*
name|deg
operator|/
literal|180.
argument_list|)
argument_list|,
name|cos
argument_list|(
name|M_PI
operator|*
name|deg
operator|/
literal|180.
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
operator|<<
name|QPolygon
argument_list|(
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
argument_list|)
expr_stmt|;
name|deg
operator|=
literal|0.00001f
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"rot 0 b"
argument_list|)
operator|<<
name|QMatrix
argument_list|(
name|cos
argument_list|(
name|M_PI
operator|*
name|deg
operator|/
literal|180.
argument_list|)
argument_list|,
operator|-
name|sin
argument_list|(
name|M_PI
operator|*
name|deg
operator|/
literal|180.
argument_list|)
argument_list|,
name|sin
argument_list|(
name|M_PI
operator|*
name|deg
operator|/
literal|180.
argument_list|)
argument_list|,
name|cos
argument_list|(
name|M_PI
operator|*
name|deg
operator|/
literal|180.
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
operator|<<
name|QPolygon
argument_list|(
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
argument_list|)
expr_stmt|;
name|deg
operator|=
literal|0.
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"rot 0 c"
argument_list|)
operator|<<
name|QMatrix
argument_list|(
name|cos
argument_list|(
name|M_PI
operator|*
name|deg
operator|/
literal|180.
argument_list|)
argument_list|,
operator|-
name|sin
argument_list|(
name|M_PI
operator|*
name|deg
operator|/
literal|180.
argument_list|)
argument_list|,
name|sin
argument_list|(
name|M_PI
operator|*
name|deg
operator|/
literal|180.
argument_list|)
argument_list|,
name|cos
argument_list|(
name|M_PI
operator|*
name|deg
operator|/
literal|180.
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
name|QRect
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
operator|<<
name|QPolygon
argument_list|(
name|QRect
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
argument_list|)
expr_stmt|;
name|deg
operator|=
literal|0.00001f
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"rot 0 d"
argument_list|)
operator|<<
name|QMatrix
argument_list|(
name|cos
argument_list|(
name|M_PI
operator|*
name|deg
operator|/
literal|180.
argument_list|)
argument_list|,
operator|-
name|sin
argument_list|(
name|M_PI
operator|*
name|deg
operator|/
literal|180.
argument_list|)
argument_list|,
name|sin
argument_list|(
name|M_PI
operator|*
name|deg
operator|/
literal|180.
argument_list|)
argument_list|,
name|cos
argument_list|(
name|M_PI
operator|*
name|deg
operator|/
literal|180.
argument_list|)
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
name|QRect
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
operator|<<
name|QPolygon
argument_list|(
name|QRect
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
argument_list|)
expr_stmt|;
if|#
directive|if
literal|0
comment|// rotations
block|deg = 90.;     QTest::newRow( "rotscale 90 a" )<< QMatrix( 10*cos( M_PI*deg/180. ), -10*sin( M_PI*deg/180. ), 						10*sin( M_PI*deg/180. ),  10*cos( M_PI*deg/180. ), 0, 0 )<< QRect( 0, 0, 30, 40 )<< QPolygon( QRect( 0, -299, 400, 300 ) );     deg = 90.00001;     QTest::newRow( "rotscale 90 b" )<< QMatrix( 10*cos( M_PI*deg/180. ), -10*sin( M_PI*deg/180. ), 						10*sin( M_PI*deg/180. ),  10*cos( M_PI*deg/180. ), 0, 0 )<< QRect( 0, 0, 30, 40 )<< QPolygon( QRect( 0, -299, 400, 300 ) );     deg = 90.;     QTest::newRow( "rotscale 90 c" )<< QMatrix( 10*cos( M_PI*deg/180. ), -10*sin( M_PI*deg/180. ), 						10*sin( M_PI*deg/180. ),  10*cos( M_PI*deg/180. ), 0, 0 )<< QRect( 10, 20, 30, 40 )<< QPolygon( QRect( 200, -399, 400, 300 ) );     deg = 90.00001;     QTest::newRow( "rotscale 90 d" )<< QMatrix( 10*cos( M_PI*deg/180. ), -10*sin( M_PI*deg/180. ), 						10*sin( M_PI*deg/180. ),  10*cos( M_PI*deg/180. ), 0, 0 )<< QRect( 10, 20, 30, 40 )<< QPolygon( QRect( 200, -399, 400, 300 ) );      deg = 180.;     QTest::newRow( "rotscale 180 a" )<< QMatrix( 10*cos( M_PI*deg/180. ), -10*sin( M_PI*deg/180. ), 						10*sin( M_PI*deg/180. ),  10*cos( M_PI*deg/180. ), 0, 0 )<< QRect( 0, 0, 30, 40 )<< QPolygon( QRect( -299, -399, 300, 400 ) );     deg = 180.000001;     QTest::newRow( "rotscale 180 b" )<< QMatrix( 10*cos( M_PI*deg/180. ), -10*sin( M_PI*deg/180. ), 						       10*sin( M_PI*deg/180. ),  10*cos( M_PI*deg/180. ), 0, 0 )<< QRect( 0, 0, 30, 40 )<< QPolygon( QRect( -299, -399, 300, 400 ) );     deg = 180.;     QTest::newRow( "rotscale 180 c" )<< QMatrix( 10*cos( M_PI*deg/180. ), -10*sin( M_PI*deg/180. ), 						10*sin( M_PI*deg/180. ),  10*cos( M_PI*deg/180. ), 0, 0 )<< QRect( 10, 20, 30, 40 )<< QPolygon( QRect( -399, -599, 300, 400 ) );     deg = 180.000001;     QTest::newRow( "rotscale 180 d" )<< QMatrix( 10*cos( M_PI*deg/180. ), -10*sin( M_PI*deg/180. ), 						10*sin( M_PI*deg/180. ),  10*cos( M_PI*deg/180. ), 0, 0 )<< QRect( 10, 20, 30, 40 )<< QPolygon( QRect( -399, -599, 300, 400 ) );      deg = 270.;     QTest::newRow( "rotscale 270 a" )<< QMatrix( 10*cos( M_PI*deg/180. ), -10*sin( M_PI*deg/180. ), 						10*sin( M_PI*deg/180. ),  10*cos( M_PI*deg/180. ), 0, 0 )<< QRect( 0, 0, 30, 40 )<< QPolygon( QRect( -399, 00, 400, 300 ) );     deg = 270.0000001;     QTest::newRow( "rotscale 270 b" )<< QMatrix( 10*cos( M_PI*deg/180. ), -10*sin( M_PI*deg/180. ), 						10*sin( M_PI*deg/180. ),  10*cos( M_PI*deg/180. ), 0, 0 )<< QRect( 0, 0, 30, 40 )<< QPolygon( QRect( -399, 00, 400, 300 ) );     deg = 270.;     QTest::newRow( "rotscale 270 c" )<< QMatrix( 10*cos( M_PI*deg/180. ), -10*sin( M_PI*deg/180. ), 						10*sin( M_PI*deg/180. ),  10*cos( M_PI*deg/180. ), 0, 0 )<< QRect( 10, 20, 30, 40 )<< QPolygon( QRect( -599, 100, 400, 300 ) );     deg = 270.000001;     QTest::newRow( "rotscale 270 d" )<< QMatrix( 10*cos( M_PI*deg/180. ), -10*sin( M_PI*deg/180. ), 						10*sin( M_PI*deg/180. ),  10*cos( M_PI*deg/180. ), 0, 	0 )<< QRect( 10, 20, 30, 40 )<< QPolygon( QRect( -599, 100, 400, 300 ) );
comment|// rotations that are not multiples of 90 degrees. mapRect returns the bounding rect here.
block|deg = 45;     QTest::newRow( "rot 45 a" )<< QMatrix( cos( M_PI*deg/180. ), -sin( M_PI*deg/180. ), 						sin( M_PI*deg/180. ),  cos( M_PI*deg/180. ), 0, 0 )<< QRect( 0, 0, 10, 10 )<< QPolygon( QRect( 0, -7, 14, 14 ) );     QTest::newRow( "rot 45 b" )<< QMatrix( cos( M_PI*deg/180. ), -sin( M_PI*deg/180. ), 						sin( M_PI*deg/180. ),  cos( M_PI*deg/180. ), 0, 0 )<< QRect( 10, 20, 30, 40 )<< QPolygon( QRect( 21, -14, 49, 49 ) );     QTest::newRow( "rot 45 c" )<< QMatrix( 10*cos( M_PI*deg/180. ), -10*sin( M_PI*deg/180. ), 						10*sin( M_PI*deg/180. ),  10*cos( M_PI*deg/180. ), 0, 0 )<< QRect( 0, 0, 10, 10 )<< QPolygon( QRect( 0, -70, 141, 141 ) );     QTest::newRow( "rot 45 d" )<< QMatrix( 10*cos( M_PI*deg/180. ), -10*sin( M_PI*deg/180. ), 						10*sin( M_PI*deg/180. ),  10*cos( M_PI*deg/180. ), 0, 0 )<< QRect( 10, 20, 30, 40 )<< QPolygon( QRect( 212, -141, 495, 495 ) );      deg = -45;     QTest::newRow( "rot -45 a" )<< QMatrix( cos( M_PI*deg/180. ), -sin( M_PI*deg/180. ), 						sin( M_PI*deg/180. ),  cos( M_PI*deg/180. ), 0, 0 )<< QRect( 0, 0, 10, 10 )<< QPolygon( QRect( -7, 0, 14, 14 ) );     QTest::newRow( "rot -45 b" )<< QMatrix( cos( M_PI*deg/180. ), -sin( M_PI*deg/180. ), 						sin( M_PI*deg/180. ),  cos( M_PI*deg/180. ), 0, 0 )<< QRect( 10, 20, 30, 40 )<< QPolygon( QRect( -35, 21, 49, 49 ) );     QTest::newRow( "rot -45 c" )<< QMatrix( 10*cos( M_PI*deg/180. ), -10*sin( M_PI*deg/180. ), 						10*sin( M_PI*deg/180. ),  10*cos( M_PI*deg/180. ), 0, 0 )<< QRect( 0, 0, 10, 10 )<< QPolygon( QRect( -70, 0, 141, 141 ) );     QTest::newRow( "rot -45 d" )<< QMatrix( 10*cos( M_PI*deg/180. ), -10*sin( M_PI*deg/180. ), 						10*sin( M_PI*deg/180. ),  10*cos( M_PI*deg/180. ), 0, 0 )<< QRect( 10, 20, 30, 40 )<< QPolygon( QRect( -353, 212, 495, 495 ) );
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|mapRect
name|void
name|tst_QWMatrix
operator|::
name|mapRect
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QMatrix
argument_list|,
name|matrix
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QRect
argument_list|,
name|src
argument_list|)
expr_stmt|;
comment|//     qDebug( "got src: %d/%d (%d/%d), matrix=[ %f %f %f %f %f %f ]",
comment|//         src.x(), src.y(), src.width(), src.height(),
comment|//         matrix.m11(), matrix.m12(), matrix.m21(), matrix.m22(), matrix.dx(), matrix.dy() );
name|QTEST
argument_list|(
name|QPolygon
argument_list|(
name|matrix
operator|.
name|mapRect
argument_list|(
name|src
argument_list|)
argument_list|)
argument_list|,
literal|"res"
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|operator_star_qrect
name|void
name|tst_QWMatrix
operator|::
name|operator_star_qrect
parameter_list|()
block|{
if|#
directive|if
literal|0
comment|// QT_VERSION>= 0x030100
block|QFETCH( QMatrix, matrix );     QFETCH( QRect, src );     QFETCH( QPolygon, res );      QCOMPARE( (matrix * src), QRegion(res) );
else|#
directive|else
name|QSKIP
argument_list|(
literal|"Not tested with Qt versions< 3.1"
argument_list|,
name|SkipAll
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|operator_star_qwmatrix
name|void
name|tst_QWMatrix
operator|::
name|operator_star_qwmatrix
parameter_list|()
block|{
if|#
directive|if
literal|0
comment|// Left out until the matrix multiply operator behaves properly..
block|QMatrix m1( 2, 3, 4, 5, 6, 7 );     QMatrix m2( 3, 4, 5, 6, 7, 8 );      QMatrix result1x2( 21, 26, 37, 46, 44, 75 );     QMatrix result2x1( 22, 29, 34, 45, 53, 80);      QMatrix product12 = m1*m2;     QMatrix product21 = m2*m1;      QVERIFY( product12==result1x2 );     QVERIFY( product21==result2x1 );
else|#
directive|else
name|QSKIP
argument_list|(
literal|"Not tested with Qt versions since the operator is broken.."
argument_list|,
name|SkipAll
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function
begin_function
DECL|function|assignments
name|void
name|tst_QWMatrix
operator|::
name|assignments
parameter_list|()
block|{
name|QMatrix
name|m
decl_stmt|;
name|m
operator|.
name|scale
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|m
operator|.
name|rotate
argument_list|(
literal|45
argument_list|)
expr_stmt|;
name|m
operator|.
name|shear
argument_list|(
literal|4
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|QMatrix
name|c1
argument_list|(
name|m
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|m
operator|.
name|m11
argument_list|()
argument_list|,
name|c1
operator|.
name|m11
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|m
operator|.
name|m12
argument_list|()
argument_list|,
name|c1
operator|.
name|m12
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|m
operator|.
name|m21
argument_list|()
argument_list|,
name|c1
operator|.
name|m21
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|m
operator|.
name|m22
argument_list|()
argument_list|,
name|c1
operator|.
name|m22
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|m
operator|.
name|dx
argument_list|()
argument_list|,
name|c1
operator|.
name|dx
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|m
operator|.
name|dy
argument_list|()
argument_list|,
name|c1
operator|.
name|dy
argument_list|()
argument_list|)
expr_stmt|;
name|QMatrix
name|c2
init|=
name|m
decl_stmt|;
name|QCOMPARE
argument_list|(
name|m
operator|.
name|m11
argument_list|()
argument_list|,
name|c2
operator|.
name|m11
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|m
operator|.
name|m12
argument_list|()
argument_list|,
name|c2
operator|.
name|m12
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|m
operator|.
name|m21
argument_list|()
argument_list|,
name|c2
operator|.
name|m21
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|m
operator|.
name|m22
argument_list|()
argument_list|,
name|c2
operator|.
name|m22
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|m
operator|.
name|dx
argument_list|()
argument_list|,
name|c2
operator|.
name|dx
argument_list|()
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|m
operator|.
name|dy
argument_list|()
argument_list|,
name|c2
operator|.
name|dy
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mapToPolygon
name|void
name|tst_QWMatrix
operator|::
name|mapToPolygon
parameter_list|()
block|{
name|QFETCH
argument_list|(
name|QMatrix
argument_list|,
name|matrix
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QRect
argument_list|,
name|src
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|QPolygon
argument_list|,
name|res
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|matrix
operator|.
name|mapToPolygon
argument_list|(
name|src
argument_list|)
argument_list|,
name|res
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|translate
name|void
name|tst_QWMatrix
operator|::
name|translate
parameter_list|()
block|{
name|QMatrix
name|m
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|,
literal|5
argument_list|,
literal|6
argument_list|)
decl_stmt|;
name|QMatrix
name|res2
argument_list|(
name|m
argument_list|)
decl_stmt|;
name|QMatrix
name|res
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|,
literal|75
argument_list|,
literal|106
argument_list|)
decl_stmt|;
name|m
operator|.
name|translate
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|m
operator|==
name|res
argument_list|)
expr_stmt|;
name|m
operator|.
name|translate
argument_list|(
operator|-
literal|10
argument_list|,
operator|-
literal|20
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|m
operator|==
name|res2
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|scale
name|void
name|tst_QWMatrix
operator|::
name|scale
parameter_list|()
block|{
name|QMatrix
name|m
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|,
literal|5
argument_list|,
literal|6
argument_list|)
decl_stmt|;
name|QMatrix
name|res2
argument_list|(
name|m
argument_list|)
decl_stmt|;
name|QMatrix
name|res
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|,
literal|60
argument_list|,
literal|80
argument_list|,
literal|5
argument_list|,
literal|6
argument_list|)
decl_stmt|;
name|m
operator|.
name|scale
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|m
operator|==
name|res
argument_list|)
expr_stmt|;
name|m
operator|.
name|scale
argument_list|(
literal|1.
operator|/
literal|10.
argument_list|,
literal|1.
operator|/
literal|20.
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|m
operator|==
name|res2
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mapPolygon
name|void
name|tst_QWMatrix
operator|::
name|mapPolygon
parameter_list|()
block|{
name|QPolygon
name|poly
decl_stmt|;
name|poly
operator|<<
name|QPoint
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|100
argument_list|,
literal|1
argument_list|)
operator|<<
name|QPoint
argument_list|(
literal|1
argument_list|,
literal|100
argument_list|)
operator|<<
name|QPoint
argument_list|(
operator|-
literal|1
argument_list|,
operator|-
literal|1
argument_list|)
operator|<<
name|QPoint
argument_list|(
operator|-
literal|1000
argument_list|,
literal|1000
argument_list|)
expr_stmt|;
block|{
name|QMatrix
name|m
decl_stmt|;
name|m
operator|.
name|rotate
argument_list|(
literal|90
argument_list|)
expr_stmt|;
comment|// rotating 90 degrees four times should result in original poly
name|QPolygon
name|mapped
init|=
name|m
operator|.
name|map
argument_list|(
name|m
operator|.
name|map
argument_list|(
name|m
operator|.
name|map
argument_list|(
name|m
operator|.
name|map
argument_list|(
name|poly
argument_list|)
argument_list|)
argument_list|)
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|mapped
argument_list|,
name|poly
argument_list|)
expr_stmt|;
name|QMatrix
name|m2
decl_stmt|;
name|m2
operator|.
name|scale
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
expr_stmt|;
name|QMatrix
name|m3
decl_stmt|;
name|m3
operator|.
name|scale
argument_list|(
literal|0.1
argument_list|,
literal|0.1
argument_list|)
expr_stmt|;
name|mapped
operator|=
name|m3
operator|.
name|map
argument_list|(
name|m2
operator|.
name|map
argument_list|(
name|poly
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|mapped
argument_list|,
name|poly
argument_list|)
expr_stmt|;
block|}
block|{
name|QMatrix
name|m
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|,
literal|5
argument_list|,
literal|6
argument_list|)
decl_stmt|;
name|QPolygon
name|mapped
init|=
name|m
operator|.
name|map
argument_list|(
name|poly
argument_list|)
decl_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|mapped
operator|.
name|size
argument_list|()
condition|;
operator|++
name|i
control|)
name|QCOMPARE
argument_list|(
name|mapped
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|,
name|m
operator|.
name|map
argument_list|(
name|poly
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_macro
name|QTEST_APPLESS_MAIN
argument_list|(
argument|tst_QWMatrix
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qwmatrix.moc"
end_include
end_unit
