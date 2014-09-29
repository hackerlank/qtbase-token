begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_include
include|#
directive|include
file|<qpicture.h>
end_include
begin_include
include|#
directive|include
file|<qpainter.h>
end_include
begin_include
include|#
directive|include
file|<qimage.h>
end_include
begin_include
include|#
directive|include
file|<qpaintengine.h>
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_WIDGETS
end_ifndef
begin_include
include|#
directive|include
file|<qdesktopwidget.h>
end_include
begin_include
include|#
directive|include
file|<qapplication.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_include
include|#
directive|include
file|<limits.h>
end_include
begin_class
DECL|class|tst_QPicture
class|class
name|tst_QPicture
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QPicture
parameter_list|()
constructor_decl|;
private|private
name|slots
private|:
name|void
name|getSetCheck
parameter_list|()
function_decl|;
name|void
name|devType
parameter_list|()
function_decl|;
name|void
name|paintingActive
parameter_list|()
function_decl|;
name|void
name|boundingRect
parameter_list|()
function_decl|;
name|void
name|swap
parameter_list|()
function_decl|;
name|void
name|serialization
parameter_list|()
function_decl|;
ifndef|#
directive|ifndef
name|QT_NO_WIDGETS
name|void
name|save_restore
parameter_list|()
function_decl|;
endif|#
directive|endif
name|void
name|boundaryValues_data
parameter_list|()
function_decl|;
name|void
name|boundaryValues
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_comment
comment|// Testing get/set functions
end_comment
begin_function
DECL|function|getSetCheck
name|void
name|tst_QPicture
operator|::
name|getSetCheck
parameter_list|()
block|{
name|QPictureIO
name|obj1
decl_stmt|;
comment|// const QPicture& QPictureIO::picture()
comment|// void QPictureIO::setPicture(const QPicture&)
comment|// const char * QPictureIO::format()
comment|// void QPictureIO::setFormat(const char *)
specifier|const
name|char
name|var2
index|[]
init|=
literal|"PNG"
decl_stmt|;
name|obj1
operator|.
name|setFormat
argument_list|(
name|var2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|var2
argument_list|,
name|obj1
operator|.
name|format
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setFormat
argument_list|(
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// The format is stored internally in a QString, so return is always a valid char *
name|QVERIFY
argument_list|(
name|QString
argument_list|(
name|obj1
operator|.
name|format
argument_list|()
argument_list|)
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
comment|// const char * QPictureIO::parameters()
comment|// void QPictureIO::setParameters(const char *)
specifier|const
name|char
name|var3
index|[]
init|=
literal|"Bogus data"
decl_stmt|;
name|obj1
operator|.
name|setParameters
argument_list|(
name|var3
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|var3
argument_list|,
name|obj1
operator|.
name|parameters
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setParameters
argument_list|(
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// The format is stored internally in a QString, so return is always a valid char *
name|QVERIFY
argument_list|(
name|QString
argument_list|(
name|obj1
operator|.
name|parameters
argument_list|()
argument_list|)
operator|.
name|isEmpty
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_constructor
DECL|function|tst_QPicture
name|tst_QPicture
operator|::
name|tst_QPicture
parameter_list|()
block|{ }
end_constructor
begin_function
DECL|function|devType
name|void
name|tst_QPicture
operator|::
name|devType
parameter_list|()
block|{
name|QPicture
name|p
decl_stmt|;
name|QCOMPARE
argument_list|(
name|p
operator|.
name|devType
argument_list|()
argument_list|,
operator|(
name|int
operator|)
name|QInternal
operator|::
name|Picture
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|paintingActive
name|void
name|tst_QPicture
operator|::
name|paintingActive
parameter_list|()
block|{
comment|// actually implemented in QPainter but QPicture is a good
comment|// example of an external paint device
name|QPicture
name|p
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|p
operator|.
name|paintingActive
argument_list|()
argument_list|)
expr_stmt|;
name|QPainter
name|pt
argument_list|(
operator|&
name|p
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|p
operator|.
name|paintingActive
argument_list|()
argument_list|)
expr_stmt|;
name|pt
operator|.
name|end
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|p
operator|.
name|paintingActive
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|boundingRect
name|void
name|tst_QPicture
operator|::
name|boundingRect
parameter_list|()
block|{
name|QPicture
name|p1
decl_stmt|;
comment|// default value
name|QVERIFY
argument_list|(
operator|!
name|p1
operator|.
name|boundingRect
argument_list|()
operator|.
name|isValid
argument_list|()
argument_list|)
expr_stmt|;
name|QRect
name|r1
argument_list|(
literal|20
argument_list|,
literal|30
argument_list|,
literal|5
argument_list|,
literal|15
argument_list|)
decl_stmt|;
name|p1
operator|.
name|setBoundingRect
argument_list|(
name|r1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p1
operator|.
name|boundingRect
argument_list|()
argument_list|,
name|r1
argument_list|)
expr_stmt|;
name|p1
operator|.
name|setBoundingRect
argument_list|(
name|QRect
argument_list|()
argument_list|)
expr_stmt|;
name|QPainter
name|pt
argument_list|(
operator|&
name|p1
argument_list|)
decl_stmt|;
name|pt
operator|.
name|drawLine
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|,
literal|110
argument_list|,
literal|80
argument_list|)
expr_stmt|;
name|pt
operator|.
name|end
argument_list|()
expr_stmt|;
comment|// assignment and copy constructor
name|QRect
name|r2
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|,
literal|100
argument_list|,
literal|60
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|p1
operator|.
name|boundingRect
argument_list|()
argument_list|,
name|r2
argument_list|)
expr_stmt|;
name|QPicture
name|p2
argument_list|(
name|p1
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|p1
operator|.
name|boundingRect
argument_list|()
argument_list|,
name|r2
argument_list|)
expr_stmt|;
name|QPicture
name|p3
decl_stmt|;
name|p3
operator|=
name|p1
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p1
operator|.
name|boundingRect
argument_list|()
argument_list|,
name|r2
argument_list|)
expr_stmt|;
block|{
name|QPicture
name|p4
decl_stmt|;
name|QPainter
name|p
argument_list|(
operator|&
name|p4
argument_list|)
decl_stmt|;
name|p
operator|.
name|drawLine
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|5
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawLine
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|p
operator|.
name|end
argument_list|()
expr_stmt|;
name|QRect
name|r3
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|5
argument_list|,
literal|5
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|p4
operator|.
name|boundingRect
argument_list|()
argument_list|,
name|r3
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|swap
name|void
name|tst_QPicture
operator|::
name|swap
parameter_list|()
block|{
name|QPicture
name|p1
decl_stmt|,
name|p2
decl_stmt|;
name|QPainter
argument_list|(
operator|&
name|p1
argument_list|)
operator|.
name|drawLine
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|5
argument_list|,
literal|5
argument_list|)
expr_stmt|;
name|QPainter
argument_list|(
operator|&
name|p2
argument_list|)
operator|.
name|drawLine
argument_list|(
literal|0
argument_list|,
literal|3
argument_list|,
literal|3
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p1
operator|.
name|boundingRect
argument_list|()
argument_list|,
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|5
argument_list|,
literal|5
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p2
operator|.
name|boundingRect
argument_list|()
argument_list|,
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|3
argument_list|,
literal|3
argument_list|)
argument_list|)
expr_stmt|;
name|p1
operator|.
name|swap
argument_list|(
name|p2
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p1
operator|.
name|boundingRect
argument_list|()
argument_list|,
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|3
argument_list|,
literal|3
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|p2
operator|.
name|boundingRect
argument_list|()
argument_list|,
name|QRect
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|5
argument_list|,
literal|5
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QDataStream::Version
argument_list|)
end_macro
begin_macro
name|Q_DECLARE_METATYPE
argument_list|(
argument|QPicture
argument_list|)
end_macro
begin_function
DECL|function|ensureSerializesCorrectly
name|void
name|ensureSerializesCorrectly
parameter_list|(
specifier|const
name|QPicture
modifier|&
name|picture
parameter_list|,
name|QDataStream
operator|::
name|Version
name|version
parameter_list|)
block|{
name|QDataStream
name|stream
decl_stmt|;
name|QBuffer
name|buffer
decl_stmt|;
name|buffer
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|WriteOnly
argument_list|)
expr_stmt|;
name|stream
operator|.
name|setDevice
argument_list|(
operator|&
name|buffer
argument_list|)
expr_stmt|;
name|stream
operator|.
name|setVersion
argument_list|(
name|version
argument_list|)
expr_stmt|;
name|stream
operator|<<
name|picture
expr_stmt|;
name|buffer
operator|.
name|close
argument_list|()
expr_stmt|;
name|buffer
operator|.
name|open
argument_list|(
name|QIODevice
operator|::
name|ReadOnly
argument_list|)
expr_stmt|;
name|QPicture
name|readpicture
decl_stmt|;
name|stream
operator|>>
name|readpicture
expr_stmt|;
name|QVERIFY2
argument_list|(
name|memcmp
argument_list|(
name|picture
operator|.
name|data
argument_list|()
argument_list|,
name|readpicture
operator|.
name|data
argument_list|()
argument_list|,
name|picture
operator|.
name|size
argument_list|()
argument_list|)
operator|==
literal|0
argument_list|,
name|qPrintable
argument_list|(
name|QString
operator|::
name|fromLatin1
argument_list|(
literal|"Picture data does not compare equal for QDataStream version %1"
argument_list|)
operator|.
name|arg
argument_list|(
name|version
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_class
DECL|class|PaintEngine
class|class
name|PaintEngine
super|:
specifier|public
name|QPaintEngine
block|{
public|public:
DECL|function|PaintEngine
name|PaintEngine
parameter_list|()
member_init_list|:
name|QPaintEngine
argument_list|()
block|{}
DECL|function|begin
name|bool
name|begin
parameter_list|(
name|QPaintDevice
modifier|*
parameter_list|)
block|{
return|return
literal|true
return|;
block|}
DECL|function|end
name|bool
name|end
parameter_list|()
block|{
return|return
literal|true
return|;
block|}
DECL|function|updateState
name|void
name|updateState
parameter_list|(
specifier|const
name|QPaintEngineState
modifier|&
parameter_list|)
block|{}
DECL|function|drawPixmap
name|void
name|drawPixmap
parameter_list|(
specifier|const
name|QRectF
modifier|&
parameter_list|,
specifier|const
name|QPixmap
modifier|&
parameter_list|,
specifier|const
name|QRectF
modifier|&
parameter_list|)
block|{}
DECL|function|type
name|Type
name|type
parameter_list|()
specifier|const
block|{
return|return
name|Raster
return|;
block|}
DECL|function|font
name|QFont
name|font
parameter_list|()
block|{
return|return
name|state
operator|->
name|font
argument_list|()
return|;
block|}
block|}
class|;
end_class
begin_class
DECL|class|Picture
class|class
name|Picture
super|:
specifier|public
name|QPicture
block|{
public|public:
DECL|function|Picture
name|Picture
parameter_list|()
member_init_list|:
name|QPicture
argument_list|()
block|{}
DECL|function|paintEngine
name|QPaintEngine
modifier|*
name|paintEngine
parameter_list|()
specifier|const
block|{
return|return
operator|(
name|QPaintEngine
operator|*
operator|)
operator|&
name|mPaintEngine
return|;
block|}
private|private:
DECL|member|mPaintEngine
name|PaintEngine
name|mPaintEngine
decl_stmt|;
block|}
class|;
end_class
begin_function
DECL|function|serialization
name|void
name|tst_QPicture
operator|::
name|serialization
parameter_list|()
block|{
name|QDataStream
name|stream
decl_stmt|;
specifier|const
name|int
name|thisVersion
init|=
name|stream
operator|.
name|version
argument_list|()
decl_stmt|;
for|for
control|(
name|int
name|version
init|=
name|QDataStream
operator|::
name|Qt_1_0
init|;
name|version
operator|<=
name|thisVersion
condition|;
operator|++
name|version
control|)
block|{
specifier|const
name|QDataStream
operator|::
name|Version
name|versionEnum
init|=
cast|static_cast
argument_list|<
name|QDataStream
operator|::
name|Version
argument_list|>
argument_list|(
name|version
argument_list|)
decl_stmt|;
block|{
comment|// streaming of null pictures
name|ensureSerializesCorrectly
argument_list|(
name|QPicture
argument_list|()
argument_list|,
name|versionEnum
argument_list|)
expr_stmt|;
block|}
block|{
comment|// picture with a simple line, checking bitwise equality
name|QPicture
name|picture
decl_stmt|;
name|QPainter
name|painter
argument_list|(
operator|&
name|picture
argument_list|)
decl_stmt|;
name|painter
operator|.
name|drawLine
argument_list|(
literal|10
argument_list|,
literal|20
argument_list|,
literal|30
argument_list|,
literal|40
argument_list|)
expr_stmt|;
name|ensureSerializesCorrectly
argument_list|(
name|picture
argument_list|,
name|versionEnum
argument_list|)
expr_stmt|;
block|}
block|}
block|{
comment|// Test features that were added after Qt 4.5, as that was hard-coded as the major
comment|// version for a while, which was incorrect. In this case, we'll test font hints.
name|QPicture
name|picture
decl_stmt|;
name|QPainter
name|painter
decl_stmt|;
name|QFont
name|font
decl_stmt|;
name|font
operator|.
name|setStyleName
argument_list|(
literal|"Blah"
argument_list|)
expr_stmt|;
name|font
operator|.
name|setHintingPreference
argument_list|(
name|QFont
operator|::
name|PreferFullHinting
argument_list|)
expr_stmt|;
name|painter
operator|.
name|begin
argument_list|(
operator|&
name|picture
argument_list|)
expr_stmt|;
name|painter
operator|.
name|setFont
argument_list|(
name|font
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawText
argument_list|(
literal|20
argument_list|,
literal|20
argument_list|,
literal|"Hello"
argument_list|)
expr_stmt|;
name|painter
operator|.
name|end
argument_list|()
expr_stmt|;
name|Picture
name|customPicture
decl_stmt|;
name|painter
operator|.
name|begin
argument_list|(
operator|&
name|customPicture
argument_list|)
expr_stmt|;
name|picture
operator|.
name|play
argument_list|(
operator|&
name|painter
argument_list|)
expr_stmt|;
specifier|const
name|QFont
name|actualFont
init|=
operator|(
operator|(
name|PaintEngine
operator|*
operator|)
name|customPicture
operator|.
name|paintEngine
argument_list|()
operator|)
operator|->
name|font
argument_list|()
decl_stmt|;
name|painter
operator|.
name|end
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|actualFont
operator|.
name|styleName
argument_list|()
argument_list|,
name|QStringLiteral
argument_list|(
literal|"Blah"
argument_list|)
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|actualFont
operator|.
name|hintingPreference
argument_list|()
argument_list|,
name|QFont
operator|::
name|PreferFullHinting
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_WIDGETS
end_ifndef
begin_function
DECL|function|scalePoint
specifier|static
name|QPointF
name|scalePoint
parameter_list|(
specifier|const
name|QPointF
modifier|&
name|point
parameter_list|,
name|QPaintDevice
modifier|*
name|sourceDevice
parameter_list|,
name|QPaintDevice
modifier|*
name|destDevice
parameter_list|)
block|{
return|return
name|QPointF
argument_list|(
name|point
operator|.
name|x
argument_list|()
operator|*
name|qreal
argument_list|(
name|destDevice
operator|->
name|logicalDpiX
argument_list|()
argument_list|)
operator|/
name|qreal
argument_list|(
name|sourceDevice
operator|->
name|logicalDpiX
argument_list|()
argument_list|)
argument_list|,
name|point
operator|.
name|y
argument_list|()
operator|*
name|qreal
argument_list|(
name|destDevice
operator|->
name|logicalDpiY
argument_list|()
argument_list|)
operator|/
name|qreal
argument_list|(
name|sourceDevice
operator|->
name|logicalDpiY
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|scaleRect
specifier|static
name|QRectF
name|scaleRect
parameter_list|(
specifier|const
name|QRectF
modifier|&
name|rect
parameter_list|,
name|QPaintDevice
modifier|*
name|sourceDevice
parameter_list|,
name|QPaintDevice
modifier|*
name|destDevice
parameter_list|)
block|{
return|return
name|QRectF
argument_list|(
name|rect
operator|.
name|left
argument_list|()
operator|*
name|qreal
argument_list|(
name|destDevice
operator|->
name|logicalDpiX
argument_list|()
argument_list|)
operator|/
name|qreal
argument_list|(
name|sourceDevice
operator|->
name|logicalDpiX
argument_list|()
argument_list|)
argument_list|,
name|rect
operator|.
name|top
argument_list|()
operator|*
name|qreal
argument_list|(
name|destDevice
operator|->
name|logicalDpiY
argument_list|()
argument_list|)
operator|/
name|qreal
argument_list|(
name|sourceDevice
operator|->
name|logicalDpiY
argument_list|()
argument_list|)
argument_list|,
name|rect
operator|.
name|width
argument_list|()
operator|*
name|qreal
argument_list|(
name|destDevice
operator|->
name|logicalDpiX
argument_list|()
argument_list|)
operator|/
name|qreal
argument_list|(
name|sourceDevice
operator|->
name|logicalDpiX
argument_list|()
argument_list|)
argument_list|,
name|rect
operator|.
name|height
argument_list|()
operator|*
name|qreal
argument_list|(
name|destDevice
operator|->
name|logicalDpiY
argument_list|()
argument_list|)
operator|/
name|qreal
argument_list|(
name|sourceDevice
operator|->
name|logicalDpiY
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|paintStuff
specifier|static
name|void
name|paintStuff
parameter_list|(
name|QPainter
modifier|*
name|p
parameter_list|)
block|{
name|QPaintDevice
modifier|*
name|screenDevice
init|=
name|QApplication
operator|::
name|desktop
argument_list|()
decl_stmt|;
name|p
operator|->
name|drawRect
argument_list|(
name|scaleRect
argument_list|(
name|QRectF
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|,
name|screenDevice
argument_list|,
name|p
operator|->
name|device
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|p
operator|->
name|save
argument_list|()
expr_stmt|;
name|p
operator|->
name|translate
argument_list|(
name|scalePoint
argument_list|(
name|QPointF
argument_list|(
literal|10
argument_list|,
literal|10
argument_list|)
argument_list|,
name|screenDevice
argument_list|,
name|p
operator|->
name|device
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|p
operator|->
name|restore
argument_list|()
expr_stmt|;
name|p
operator|->
name|drawRect
argument_list|(
name|scaleRect
argument_list|(
name|QRectF
argument_list|(
literal|100
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|,
literal|100
argument_list|)
argument_list|,
name|screenDevice
argument_list|,
name|p
operator|->
name|device
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/* See task: 41469    Problem is that the state is not properly restored if the basestate of    the painter is different when the picture data was created compared to    the base state of the painter when it is played back.  */
end_comment
begin_function
DECL|function|save_restore
name|void
name|tst_QPicture
operator|::
name|save_restore
parameter_list|()
block|{
name|QPicture
name|pic
decl_stmt|;
name|QPainter
name|p
decl_stmt|;
name|p
operator|.
name|begin
argument_list|(
operator|&
name|pic
argument_list|)
expr_stmt|;
name|paintStuff
argument_list|(
operator|&
name|p
argument_list|)
expr_stmt|;
name|p
operator|.
name|end
argument_list|()
expr_stmt|;
name|QPixmap
name|pix1
argument_list|(
literal|300
argument_list|,
literal|300
argument_list|)
decl_stmt|;
name|pix1
operator|.
name|fill
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|p
operator|.
name|begin
argument_list|(
operator|&
name|pix1
argument_list|)
expr_stmt|;
name|p
operator|.
name|drawPicture
argument_list|(
literal|50
argument_list|,
literal|50
argument_list|,
name|pic
argument_list|)
expr_stmt|;
name|p
operator|.
name|end
argument_list|()
expr_stmt|;
name|QPixmap
name|pix2
argument_list|(
literal|300
argument_list|,
literal|300
argument_list|)
decl_stmt|;
name|pix2
operator|.
name|fill
argument_list|(
name|Qt
operator|::
name|white
argument_list|)
expr_stmt|;
name|p
operator|.
name|begin
argument_list|(
operator|&
name|pix2
argument_list|)
expr_stmt|;
name|p
operator|.
name|translate
argument_list|(
literal|50
argument_list|,
literal|50
argument_list|)
expr_stmt|;
name|paintStuff
argument_list|(
operator|&
name|p
argument_list|)
expr_stmt|;
name|p
operator|.
name|end
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|pix1
operator|.
name|toImage
argument_list|()
operator|==
name|pix2
operator|.
name|toImage
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_endif
endif|#
directive|endif
end_endif
begin_function
DECL|function|boundaryValues_data
name|void
name|tst_QPicture
operator|::
name|boundaryValues_data
parameter_list|()
block|{
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"x"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|addColumn
argument_list|<
name|int
argument_list|>
argument_list|(
literal|"y"
argument_list|)
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"max x"
argument_list|)
operator|<<
name|INT_MAX
operator|<<
literal|50
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"max y"
argument_list|)
operator|<<
literal|50
operator|<<
name|INT_MAX
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"max x and y"
argument_list|)
operator|<<
name|INT_MAX
operator|<<
name|INT_MAX
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"min x"
argument_list|)
operator|<<
name|INT_MIN
operator|<<
literal|50
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"min y"
argument_list|)
operator|<<
literal|50
operator|<<
name|INT_MIN
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"min x and y"
argument_list|)
operator|<<
name|INT_MIN
operator|<<
name|INT_MIN
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"min x, max y"
argument_list|)
operator|<<
name|INT_MIN
operator|<<
name|INT_MAX
expr_stmt|;
name|QTest
operator|::
name|newRow
argument_list|(
literal|"max x, min y"
argument_list|)
operator|<<
name|INT_MAX
operator|<<
name|INT_MIN
expr_stmt|;
block|}
end_function
begin_function
DECL|function|boundaryValues
name|void
name|tst_QPicture
operator|::
name|boundaryValues
parameter_list|()
block|{
name|QPicture
name|picture
decl_stmt|;
name|QPainter
name|painter
decl_stmt|;
name|painter
operator|.
name|begin
argument_list|(
operator|&
name|picture
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|QFETCH
argument_list|(
name|int
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|painter
operator|.
name|drawPoint
argument_list|(
name|QPoint
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
argument_list|)
expr_stmt|;
name|painter
operator|.
name|end
argument_list|()
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QPicture
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qpicture.moc"
end_include
end_unit
