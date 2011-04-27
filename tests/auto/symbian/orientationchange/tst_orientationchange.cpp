begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the test suite of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<QtTest/QtTest>
end_include
begin_ifdef
ifdef|#
directive|ifdef
name|Q_OS_SYMBIAN
end_ifdef
begin_include
include|#
directive|include
file|<eikenv.h>
end_include
begin_include
include|#
directive|include
file|<aknappui.h>
end_include
begin_include
include|#
directive|include
file|<private/qcore_symbian_p.h>
end_include
begin_include
include|#
directive|include
file|<QDesktopWidget>
end_include
begin_class
DECL|class|tst_orientationchange
class|class
name|tst_orientationchange
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
public|public:
DECL|function|tst_orientationchange
name|tst_orientationchange
parameter_list|()
block|{}
empty_stmt|;
DECL|function|~tst_orientationchange
name|~
name|tst_orientationchange
parameter_list|()
block|{}
empty_stmt|;
private|private
name|slots
private|:
name|void
name|resizeEventOnOrientationChange
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_class
DECL|class|TestWidget
class|class
name|TestWidget
super|:
specifier|public
name|QWidget
block|{
public|public:
name|TestWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
init|=
literal|0
parameter_list|)
constructor_decl|;
name|void
name|reset
parameter_list|()
function_decl|;
public|public:
name|void
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
name|event
parameter_list|)
function_decl|;
public|public:
DECL|member|resizeEventSize
name|QSize
name|resizeEventSize
decl_stmt|;
DECL|member|resizeEventCount
name|int
name|resizeEventCount
decl_stmt|;
block|}
class|;
end_class
begin_constructor
DECL|function|TestWidget
name|TestWidget
operator|::
name|TestWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidget
argument_list|(
name|parent
argument_list|)
block|{
name|reset
argument_list|()
expr_stmt|;
block|}
end_constructor
begin_function
DECL|function|reset
name|void
name|TestWidget
operator|::
name|reset
parameter_list|()
block|{
name|resizeEventSize
operator|=
name|QSize
argument_list|()
expr_stmt|;
name|resizeEventCount
operator|=
literal|0
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resizeEvent
name|void
name|TestWidget
operator|::
name|resizeEvent
parameter_list|(
name|QResizeEvent
modifier|*
name|event
parameter_list|)
block|{
name|QWidget
operator|::
name|resizeEvent
argument_list|(
name|event
argument_list|)
expr_stmt|;
comment|// Size delivered in first resize event is stored.
if|if
condition|(
operator|!
name|resizeEventCount
condition|)
name|resizeEventSize
operator|=
name|event
operator|->
name|size
argument_list|()
expr_stmt|;
name|resizeEventCount
operator|++
expr_stmt|;
block|}
end_function
begin_function
DECL|function|resizeEventOnOrientationChange
name|void
name|tst_orientationchange
operator|::
name|resizeEventOnOrientationChange
parameter_list|()
block|{
comment|// This will test that when orientation 'changes', then
comment|// at most one resize event is generated.
name|TestWidget
modifier|*
name|normalWidget
init|=
operator|new
name|TestWidget
argument_list|()
decl_stmt|;
name|TestWidget
modifier|*
name|fullScreenWidget
init|=
operator|new
name|TestWidget
argument_list|()
decl_stmt|;
name|TestWidget
modifier|*
name|maximizedWidget
init|=
operator|new
name|TestWidget
argument_list|()
decl_stmt|;
name|fullScreenWidget
operator|->
name|showFullScreen
argument_list|()
expr_stmt|;
name|maximizedWidget
operator|->
name|showMaximized
argument_list|()
expr_stmt|;
name|normalWidget
operator|->
name|show
argument_list|()
expr_stmt|;
name|QCoreApplication
operator|::
name|sendPostedEvents
argument_list|()
expr_stmt|;
name|QCoreApplication
operator|::
name|sendPostedEvents
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|fullScreenWidget
operator|->
name|resizeEventCount
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|fullScreenWidget
operator|->
name|size
argument_list|()
argument_list|,
name|fullScreenWidget
operator|->
name|resizeEventSize
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|maximizedWidget
operator|->
name|resizeEventCount
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|maximizedWidget
operator|->
name|size
argument_list|()
argument_list|,
name|maximizedWidget
operator|->
name|resizeEventSize
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|normalWidget
operator|->
name|resizeEventCount
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|normalWidget
operator|->
name|size
argument_list|()
argument_list|,
name|normalWidget
operator|->
name|resizeEventSize
argument_list|)
expr_stmt|;
name|fullScreenWidget
operator|->
name|reset
argument_list|()
expr_stmt|;
name|maximizedWidget
operator|->
name|reset
argument_list|()
expr_stmt|;
name|normalWidget
operator|->
name|reset
argument_list|()
expr_stmt|;
comment|// Assumes that Qt application is AVKON application.
name|CAknAppUi
modifier|*
name|appUi
init|=
cast|static_cast
argument_list|<
name|CAknAppUi
operator|*
argument_list|>
argument_list|(
name|CEikonEnv
operator|::
name|Static
argument_list|()
operator|->
name|EikAppUi
argument_list|()
argument_list|)
decl_stmt|;
comment|// Determine 'opposite' orientation to the current orientation.
name|CAknAppUi
operator|::
name|TAppUiOrientation
name|orientation
init|=
name|CAknAppUi
operator|::
name|EAppUiOrientationLandscape
decl_stmt|;
if|if
condition|(
name|fullScreenWidget
operator|->
name|size
argument_list|()
operator|.
name|width
argument_list|()
operator|>
name|fullScreenWidget
operator|->
name|size
argument_list|()
operator|.
name|height
argument_list|()
condition|)
block|{
name|orientation
operator|=
name|CAknAppUi
operator|::
name|EAppUiOrientationPortrait
expr_stmt|;
block|}
name|TRAPD
argument_list|(
name|err
argument_list|,
name|appUi
operator|->
name|SetOrientationL
argument_list|(
name|orientation
argument_list|)
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|sendPostedEvents
argument_list|()
expr_stmt|;
name|QCoreApplication
operator|::
name|sendPostedEvents
argument_list|()
expr_stmt|;
comment|// setOrientationL is not guaranteed to change orientation
comment|// (if emulator configured to support just portrait or landscape, then
comment|//  setOrientationL call shouldn't do anything).
comment|// So let's ensure that we do not get resize event twice.
name|QVERIFY
argument_list|(
name|fullScreenWidget
operator|->
name|resizeEventCount
operator|<=
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|fullScreenWidget
operator|->
name|resizeEventCount
condition|)
block|{
name|QCOMPARE
argument_list|(
name|fullScreenWidget
operator|->
name|size
argument_list|()
argument_list|,
name|fullScreenWidget
operator|->
name|resizeEventSize
argument_list|)
expr_stmt|;
block|}
name|QVERIFY
argument_list|(
name|maximizedWidget
operator|->
name|resizeEventCount
operator|<=
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|fullScreenWidget
operator|->
name|resizeEventCount
condition|)
block|{
name|QCOMPARE
argument_list|(
name|maximizedWidget
operator|->
name|size
argument_list|()
argument_list|,
name|maximizedWidget
operator|->
name|resizeEventSize
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|normalWidget
operator|->
name|resizeEventCount
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|QDesktopWidget
name|desktop
decl_stmt|;
name|QRect
name|qtAvail
init|=
name|desktop
operator|.
name|availableGeometry
argument_list|(
name|normalWidget
argument_list|)
decl_stmt|;
name|TRect
name|clientRect
init|=
cast|static_cast
argument_list|<
name|CEikAppUi
operator|*
argument_list|>
argument_list|(
name|CCoeEnv
operator|::
name|Static
argument_list|()
operator|->
name|AppUi
argument_list|()
argument_list|)
operator|->
name|ClientRect
argument_list|()
decl_stmt|;
name|QRect
name|symbianAvail
init|=
name|qt_TRect2QRect
argument_list|(
name|clientRect
argument_list|)
decl_stmt|;
name|QCOMPARE
argument_list|(
name|qtAvail
argument_list|,
name|symbianAvail
argument_list|)
expr_stmt|;
comment|// Switch orientation back to original
name|orientation
operator|=
name|orientation
operator|==
name|CAknAppUi
operator|::
name|EAppUiOrientationPortrait
condition|?
name|CAknAppUi
operator|::
name|EAppUiOrientationLandscape
else|:
name|CAknAppUi
operator|::
name|EAppUiOrientationPortrait
expr_stmt|;
name|fullScreenWidget
operator|->
name|reset
argument_list|()
expr_stmt|;
name|maximizedWidget
operator|->
name|reset
argument_list|()
expr_stmt|;
name|normalWidget
operator|->
name|reset
argument_list|()
expr_stmt|;
name|TRAP
argument_list|(
name|err
argument_list|,
name|appUi
operator|->
name|SetOrientationL
argument_list|(
name|orientation
argument_list|)
argument_list|)
expr_stmt|;
name|QCoreApplication
operator|::
name|sendPostedEvents
argument_list|()
expr_stmt|;
name|QCoreApplication
operator|::
name|sendPostedEvents
argument_list|()
expr_stmt|;
comment|// setOrientationL is not guaranteed to change orientation
comment|// (if emulator configured to support just portrait or landscape, then
comment|//  setOrientationL call shouldn't do anything).
comment|// So let's ensure that we do not get resize event twice.
name|QVERIFY
argument_list|(
name|fullScreenWidget
operator|->
name|resizeEventCount
operator|<=
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|fullScreenWidget
operator|->
name|resizeEventCount
condition|)
block|{
name|QCOMPARE
argument_list|(
name|fullScreenWidget
operator|->
name|size
argument_list|()
argument_list|,
name|fullScreenWidget
operator|->
name|resizeEventSize
argument_list|)
expr_stmt|;
block|}
name|QVERIFY
argument_list|(
name|maximizedWidget
operator|->
name|resizeEventCount
operator|<=
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|fullScreenWidget
operator|->
name|resizeEventCount
condition|)
block|{
name|QCOMPARE
argument_list|(
name|maximizedWidget
operator|->
name|size
argument_list|()
argument_list|,
name|maximizedWidget
operator|->
name|resizeEventSize
argument_list|)
expr_stmt|;
block|}
name|QCOMPARE
argument_list|(
name|normalWidget
operator|->
name|resizeEventCount
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|qtAvail
operator|=
name|desktop
operator|.
name|availableGeometry
argument_list|(
name|normalWidget
argument_list|)
expr_stmt|;
name|clientRect
operator|=
cast|static_cast
argument_list|<
name|CEikAppUi
operator|*
argument_list|>
argument_list|(
name|CCoeEnv
operator|::
name|Static
argument_list|()
operator|->
name|AppUi
argument_list|()
argument_list|)
operator|->
name|ClientRect
argument_list|()
expr_stmt|;
name|symbianAvail
operator|=
name|qt_TRect2QRect
argument_list|(
name|clientRect
argument_list|)
expr_stmt|;
name|QCOMPARE
argument_list|(
name|qtAvail
argument_list|,
name|symbianAvail
argument_list|)
expr_stmt|;
name|TRAP
argument_list|(
name|err
argument_list|,
name|appUi
operator|->
name|SetOrientationL
argument_list|(
name|CAknAppUi
operator|::
name|EAppUiOrientationUnspecified
argument_list|)
argument_list|)
expr_stmt|;
operator|delete
name|normalWidget
expr_stmt|;
operator|delete
name|fullScreenWidget
expr_stmt|;
operator|delete
name|maximizedWidget
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_orientationchange
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_orientationchange.moc"
end_include
begin_else
else|#
directive|else
end_else
begin_macro
name|QTEST_NOOP_MAIN
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
