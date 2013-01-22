begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
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
file|<qpaintengine.h>
end_include
begin_include
include|#
directive|include
file|<qpixmap.h>
end_include
begin_class
DECL|class|tst_QPaintEngine
class|class
name|tst_QPaintEngine
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
name|tst_QPaintEngine
parameter_list|()
constructor_decl|;
specifier|virtual
name|~
name|tst_QPaintEngine
parameter_list|()
destructor_decl|;
private|private
name|slots
private|:
name|void
name|getSetCheck
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_constructor
DECL|function|tst_QPaintEngine
name|tst_QPaintEngine
operator|::
name|tst_QPaintEngine
parameter_list|()
block|{ }
end_constructor
begin_destructor
DECL|function|~tst_QPaintEngine
name|tst_QPaintEngine
operator|::
name|~
name|tst_QPaintEngine
parameter_list|()
block|{ }
end_destructor
begin_class
DECL|class|MyPaintEngine
class|class
name|MyPaintEngine
super|:
specifier|public
name|QPaintEngine
block|{
public|public:
DECL|function|MyPaintEngine
name|MyPaintEngine
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
block|}
class|;
end_class
begin_comment
comment|// Testing get/set functions
end_comment
begin_function
DECL|function|getSetCheck
name|void
name|tst_QPaintEngine
operator|::
name|getSetCheck
parameter_list|()
block|{
name|MyPaintEngine
name|obj1
decl_stmt|;
comment|// QPaintDevice * QPaintEngine::paintDevice()
comment|// void QPaintEngine::setPaintDevice(QPaintDevice *)
name|QPixmap
modifier|*
name|var1
init|=
operator|new
name|QPixmap
decl_stmt|;
name|obj1
operator|.
name|setPaintDevice
argument_list|(
name|var1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|(
name|QPaintDevice
operator|*
operator|)
name|var1
argument_list|,
name|obj1
operator|.
name|paintDevice
argument_list|()
argument_list|)
expr_stmt|;
name|obj1
operator|.
name|setPaintDevice
argument_list|(
operator|(
name|QPaintDevice
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
operator|(
name|QPaintDevice
operator|*
operator|)
literal|0
argument_list|,
name|obj1
operator|.
name|paintDevice
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|var1
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QPaintEngine
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qpaintengine.moc"
end_include
end_unit
