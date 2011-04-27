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
file|<qapplication.h>
end_include
begin_include
include|#
directive|include
file|<qtoolbar.h>
end_include
begin_include
include|#
directive|include
file|<qcombobox.h>
end_include
begin_include
include|#
directive|include
file|<qwidgetaction.h>
end_include
begin_include
include|#
directive|include
file|<qlabel.h>
end_include
begin_include
include|#
directive|include
file|<qmenu.h>
end_include
begin_include
include|#
directive|include
file|<qmainwindow.h>
end_include
begin_include
include|#
directive|include
file|<qmenubar.h>
end_include
begin_include
include|#
directive|include
file|"../../shared/util.h"
end_include
begin_comment
comment|//TESTED_CLASS=
end_comment
begin_comment
comment|//TESTED_FILES=
end_comment
begin_class
DECL|class|tst_QWidgetAction
class|class
name|tst_QWidgetAction
super|:
specifier|public
name|QObject
block|{
name|Q_OBJECT
private|private
name|slots
private|:
name|void
name|defaultWidget
parameter_list|()
function_decl|;
name|void
name|visibilityUpdate
parameter_list|()
function_decl|;
name|void
name|customWidget
parameter_list|()
function_decl|;
name|void
name|keepOwnership
parameter_list|()
function_decl|;
name|void
name|visibility
parameter_list|()
function_decl|;
name|void
name|setEnabled
parameter_list|()
function_decl|;
name|void
name|popup
parameter_list|()
function_decl|;
name|void
name|releaseWidgetCrash
parameter_list|()
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|defaultWidget
name|void
name|tst_QWidgetAction
operator|::
name|defaultWidget
parameter_list|()
block|{
block|{
name|QToolBar
name|tb1
decl_stmt|;
name|QPointer
argument_list|<
name|QComboBox
argument_list|>
name|combo
init|=
operator|new
name|QComboBox
argument_list|(
operator|&
name|tb1
argument_list|)
decl_stmt|;
name|QWidgetAction
modifier|*
name|action
init|=
operator|new
name|QWidgetAction
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|action
operator|->
name|setDefaultWidget
argument_list|(
name|combo
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|combo
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|combo
operator|->
name|parent
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|action
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|action
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|combo
argument_list|)
expr_stmt|;
block|}
block|{
name|QToolBar
name|tb1
decl_stmt|;
name|QPointer
argument_list|<
name|QComboBox
argument_list|>
name|combo
init|=
operator|new
name|QComboBox
argument_list|(
operator|&
name|tb1
argument_list|)
decl_stmt|;
name|combo
operator|->
name|hide
argument_list|()
expr_stmt|;
name|QWidgetAction
modifier|*
name|action
init|=
operator|new
name|QWidgetAction
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|action
operator|->
name|setDefaultWidget
argument_list|(
name|combo
argument_list|)
expr_stmt|;
comment|// explicitly hidden widgets should also set the action invisible
name|QVERIFY
argument_list|(
operator|!
name|action
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|action
expr_stmt|;
block|}
block|{
name|QPointer
argument_list|<
name|QComboBox
argument_list|>
name|combo
init|=
operator|new
name|QComboBox
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|combo
operator|->
name|show
argument_list|()
expr_stmt|;
name|QWidgetAction
modifier|*
name|action
init|=
operator|new
name|QWidgetAction
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|action
operator|->
name|setDefaultWidget
argument_list|(
name|combo
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|action
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|combo
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|action
expr_stmt|;
block|}
block|{
name|QToolBar
name|tb1
decl_stmt|;
name|tb1
operator|.
name|show
argument_list|()
expr_stmt|;
name|QToolBar
name|tb2
decl_stmt|;
name|tb2
operator|.
name|show
argument_list|()
expr_stmt|;
name|QPointer
argument_list|<
name|QComboBox
argument_list|>
name|combo
init|=
operator|new
name|QComboBox
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QWidgetAction
modifier|*
name|action
init|=
operator|new
name|QWidgetAction
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|action
operator|->
name|setDefaultWidget
argument_list|(
name|combo
argument_list|)
expr_stmt|;
name|tb1
operator|.
name|addAction
argument_list|(
name|action
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|combo
operator|->
name|parent
argument_list|()
operator|==
operator|&
name|tb1
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|combo
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
comment|// not supported, not supposed to work, hence the parent() check
name|tb2
operator|.
name|addAction
argument_list|(
name|action
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|combo
operator|->
name|parent
argument_list|()
operator|==
operator|&
name|tb1
argument_list|)
expr_stmt|;
name|tb2
operator|.
name|removeAction
argument_list|(
name|action
argument_list|)
expr_stmt|;
name|tb1
operator|.
name|removeAction
argument_list|(
name|action
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
comment|//the call to hide is delayd by the toolbar layout
name|QVERIFY
argument_list|(
operator|!
name|combo
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|tb2
operator|.
name|addAction
argument_list|(
name|action
argument_list|)
expr_stmt|;
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
comment|//the call to hide is delayd by the toolbar layout
name|qApp
operator|->
name|processEvents
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|combo
operator|->
name|parent
argument_list|()
operator|==
operator|&
name|tb2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|combo
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|tb1
operator|.
name|addAction
argument_list|(
name|action
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|combo
operator|->
name|parent
argument_list|()
operator|==
operator|&
name|tb2
argument_list|)
expr_stmt|;
operator|delete
name|action
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|combo
argument_list|)
expr_stmt|;
block|}
block|{
name|QWidgetAction
modifier|*
name|a
init|=
operator|new
name|QWidgetAction
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|a
operator|->
name|defaultWidget
argument_list|()
argument_list|)
expr_stmt|;
name|QPointer
argument_list|<
name|QComboBox
argument_list|>
name|combo1
init|=
operator|new
name|QComboBox
decl_stmt|;
name|a
operator|->
name|setDefaultWidget
argument_list|(
name|combo1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|a
operator|->
name|defaultWidget
argument_list|()
operator|==
name|combo1
argument_list|)
expr_stmt|;
name|a
operator|->
name|setDefaultWidget
argument_list|(
name|combo1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|combo1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|a
operator|->
name|defaultWidget
argument_list|()
operator|==
name|combo1
argument_list|)
expr_stmt|;
name|QPointer
argument_list|<
name|QComboBox
argument_list|>
name|combo2
init|=
operator|new
name|QComboBox
decl_stmt|;
name|QVERIFY
argument_list|(
name|combo1
operator|!=
name|combo2
argument_list|)
expr_stmt|;
name|a
operator|->
name|setDefaultWidget
argument_list|(
name|combo2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|combo1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|a
operator|->
name|defaultWidget
argument_list|()
operator|==
name|combo2
argument_list|)
expr_stmt|;
operator|delete
name|a
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|combo2
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|visibilityUpdate
name|void
name|tst_QWidgetAction
operator|::
name|visibilityUpdate
parameter_list|()
block|{
comment|// actually keeping the widget's state in sync with the
comment|// action in terms of visibility is QToolBar's responsibility.
name|QToolBar
name|tb
decl_stmt|;
name|tb
operator|.
name|show
argument_list|()
expr_stmt|;
name|QComboBox
modifier|*
name|combo
init|=
operator|new
name|QComboBox
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QWidgetAction
modifier|*
name|action
init|=
operator|new
name|QWidgetAction
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|action
operator|->
name|setDefaultWidget
argument_list|(
name|combo
argument_list|)
expr_stmt|;
name|tb
operator|.
name|addAction
argument_list|(
name|action
argument_list|)
expr_stmt|;
comment|//the call to show is delayed by the toolbar layout
name|QTRY_VERIFY
argument_list|(
name|combo
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|action
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|action
operator|->
name|setVisible
argument_list|(
literal|false
argument_list|)
expr_stmt|;
comment|//the call to hide is delayed by the toolbar layout
name|QTRY_VERIFY
argument_list|(
operator|!
name|combo
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|action
expr_stmt|;
comment|// action also deletes combo
block|}
end_function
begin_class
DECL|class|ComboAction
class|class
name|ComboAction
super|:
specifier|public
name|QWidgetAction
block|{
public|public:
DECL|function|ComboAction
specifier|inline
name|ComboAction
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidgetAction
argument_list|(
name|parent
argument_list|)
block|{}
DECL|function|createdWidgets
name|QList
argument_list|<
name|QWidget
modifier|*
argument_list|>
name|createdWidgets
parameter_list|()
specifier|const
block|{
return|return
name|QWidgetAction
operator|::
name|createdWidgets
argument_list|()
return|;
block|}
protected|protected:
specifier|virtual
name|QWidget
modifier|*
name|createWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
function_decl|;
block|}
class|;
end_class
begin_function
DECL|function|createWidget
name|QWidget
modifier|*
name|ComboAction
operator|::
name|createWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
block|{
return|return
operator|new
name|QComboBox
argument_list|(
name|parent
argument_list|)
return|;
block|}
end_function
begin_function
DECL|function|customWidget
name|void
name|tst_QWidgetAction
operator|::
name|customWidget
parameter_list|()
block|{
name|QToolBar
name|tb1
decl_stmt|;
name|tb1
operator|.
name|show
argument_list|()
expr_stmt|;
name|QToolBar
name|tb2
decl_stmt|;
name|tb2
operator|.
name|show
argument_list|()
expr_stmt|;
name|ComboAction
modifier|*
name|action
init|=
operator|new
name|ComboAction
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|tb1
operator|.
name|addAction
argument_list|(
name|action
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QWidget
modifier|*
argument_list|>
name|combos
init|=
name|action
operator|->
name|createdWidgets
argument_list|()
decl_stmt|;
name|QCOMPARE
argument_list|(
name|combos
operator|.
name|count
argument_list|()
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|QPointer
argument_list|<
name|QComboBox
argument_list|>
name|combo1
init|=
name|qobject_cast
argument_list|<
name|QComboBox
operator|*
argument_list|>
argument_list|(
name|combos
operator|.
name|at
argument_list|(
literal|0
argument_list|)
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|combo1
argument_list|)
expr_stmt|;
name|tb2
operator|.
name|addAction
argument_list|(
name|action
argument_list|)
expr_stmt|;
name|combos
operator|=
name|action
operator|->
name|createdWidgets
argument_list|()
expr_stmt|;
name|QCOMPARE
argument_list|(
name|combos
operator|.
name|count
argument_list|()
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|combos
operator|.
name|at
argument_list|(
literal|0
argument_list|)
operator|==
name|combo1
argument_list|)
expr_stmt|;
name|QPointer
argument_list|<
name|QComboBox
argument_list|>
name|combo2
init|=
name|qobject_cast
argument_list|<
name|QComboBox
operator|*
argument_list|>
argument_list|(
name|combos
operator|.
name|at
argument_list|(
literal|1
argument_list|)
argument_list|)
decl_stmt|;
name|QVERIFY
argument_list|(
name|combo2
argument_list|)
expr_stmt|;
name|tb2
operator|.
name|removeAction
argument_list|(
name|action
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|combo2
argument_list|)
expr_stmt|;
comment|// widget is deleted using deleteLater(), so process that posted event
name|QCoreApplication
operator|::
name|sendPostedEvents
argument_list|(
name|combo2
argument_list|,
name|QEvent
operator|::
name|DeferredDelete
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|combo2
argument_list|)
expr_stmt|;
operator|delete
name|action
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|combo1
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|combo2
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|keepOwnership
name|void
name|tst_QWidgetAction
operator|::
name|keepOwnership
parameter_list|()
block|{
name|QPointer
argument_list|<
name|QComboBox
argument_list|>
name|combo
init|=
operator|new
name|QComboBox
decl_stmt|;
name|QWidgetAction
modifier|*
name|action
init|=
operator|new
name|QWidgetAction
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|action
operator|->
name|setDefaultWidget
argument_list|(
name|combo
argument_list|)
expr_stmt|;
block|{
name|QToolBar
modifier|*
name|tb
init|=
operator|new
name|QToolBar
decl_stmt|;
name|tb
operator|->
name|addAction
argument_list|(
name|action
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|combo
operator|->
name|parent
argument_list|()
operator|==
name|tb
argument_list|)
expr_stmt|;
operator|delete
name|tb
expr_stmt|;
block|}
name|QVERIFY
argument_list|(
name|combo
argument_list|)
expr_stmt|;
operator|delete
name|action
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|combo
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|visibility
name|void
name|tst_QWidgetAction
operator|::
name|visibility
parameter_list|()
block|{
block|{
name|QWidgetAction
modifier|*
name|a
init|=
operator|new
name|QWidgetAction
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QComboBox
modifier|*
name|combo
init|=
operator|new
name|QComboBox
decl_stmt|;
name|a
operator|->
name|setDefaultWidget
argument_list|(
name|combo
argument_list|)
expr_stmt|;
name|QToolBar
modifier|*
name|tb
init|=
operator|new
name|QToolBar
decl_stmt|;
name|tb
operator|->
name|addAction
argument_list|(
name|a
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|combo
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|tb
operator|->
name|show
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|combo
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|tb
expr_stmt|;
operator|delete
name|a
expr_stmt|;
block|}
block|{
name|QWidgetAction
modifier|*
name|a
init|=
operator|new
name|QWidgetAction
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|QComboBox
modifier|*
name|combo
init|=
operator|new
name|QComboBox
decl_stmt|;
name|a
operator|->
name|setDefaultWidget
argument_list|(
name|combo
argument_list|)
expr_stmt|;
name|QToolBar
modifier|*
name|tb
init|=
operator|new
name|QToolBar
decl_stmt|;
name|tb
operator|->
name|addAction
argument_list|(
name|a
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|combo
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|QToolBar
modifier|*
name|tb2
init|=
operator|new
name|QToolBar
decl_stmt|;
name|tb
operator|->
name|removeAction
argument_list|(
name|a
argument_list|)
expr_stmt|;
name|tb2
operator|->
name|addAction
argument_list|(
name|a
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|combo
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
name|tb2
operator|->
name|show
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|combo
operator|->
name|isVisible
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|tb
expr_stmt|;
operator|delete
name|tb2
expr_stmt|;
operator|delete
name|a
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|setEnabled
name|void
name|tst_QWidgetAction
operator|::
name|setEnabled
parameter_list|()
block|{
name|QToolBar
name|toolbar
decl_stmt|;
name|QComboBox
modifier|*
name|combobox
init|=
operator|new
name|QComboBox
decl_stmt|;
name|QAction
modifier|*
name|action
init|=
name|toolbar
operator|.
name|addWidget
argument_list|(
name|combobox
argument_list|)
decl_stmt|;
name|toolbar
operator|.
name|show
argument_list|()
expr_stmt|;
name|QVERIFY
argument_list|(
name|action
operator|->
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|combobox
operator|->
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
name|action
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|action
operator|->
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|combobox
operator|->
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
name|action
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|action
operator|->
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|combobox
operator|->
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
name|combobox
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|combobox
operator|->
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
name|combobox
operator|->
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|action
operator|->
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|combobox
operator|->
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
name|QWidgetAction
name|aw
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|aw
operator|.
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|aw
operator|.
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
name|combobox
operator|=
operator|new
name|QComboBox
expr_stmt|;
name|aw
operator|.
name|setDefaultWidget
argument_list|(
name|combobox
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|aw
operator|.
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|combobox
operator|->
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
comment|// Make sure we don't change the default widget's Qt::WA_ForceDisabled attribute
comment|// during a normal disable/enable operation (task 207433).
block|{
name|QToolBar
name|toolBar
decl_stmt|;
name|QWidget
name|widget
decl_stmt|;
name|toolBar
operator|.
name|addWidget
argument_list|(
operator|&
name|widget
argument_list|)
expr_stmt|;
comment|// creates a QWidgetAction and sets 'widget' as the default widget.
name|QVERIFY
argument_list|(
operator|!
name|widget
operator|.
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_ForceDisabled
argument_list|)
argument_list|)
expr_stmt|;
name|toolBar
operator|.
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|toolBar
operator|.
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_ForceDisabled
argument_list|)
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|widget
operator|.
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|widget
operator|.
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_ForceDisabled
argument_list|)
argument_list|)
expr_stmt|;
name|toolBar
operator|.
name|setEnabled
argument_list|(
literal|true
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
name|widget
operator|.
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
name|QVERIFY
argument_list|(
operator|!
name|widget
operator|.
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_ForceDisabled
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function
begin_function
DECL|function|popup
name|void
name|tst_QWidgetAction
operator|::
name|popup
parameter_list|()
block|{
name|QPointer
argument_list|<
name|QLabel
argument_list|>
name|l
init|=
operator|new
name|QLabel
argument_list|(
literal|"test"
argument_list|)
decl_stmt|;
name|QWidgetAction
name|action
argument_list|(
literal|0
argument_list|)
decl_stmt|;
name|action
operator|.
name|setDefaultWidget
argument_list|(
name|l
argument_list|)
expr_stmt|;
block|{
name|QMenu
name|menu
decl_stmt|;
name|menu
operator|.
name|addAction
argument_list|(
operator|&
name|action
argument_list|)
expr_stmt|;
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|0
argument_list|,
operator|&
name|menu
argument_list|,
name|SLOT
argument_list|(
name|close
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
name|menu
operator|.
name|exec
argument_list|()
expr_stmt|;
block|}
name|QVERIFY
argument_list|(
operator|!
name|l
operator|.
name|isNull
argument_list|()
argument_list|)
expr_stmt|;
operator|delete
name|l
expr_stmt|;
block|}
end_function
begin_class
DECL|class|CrashedAction
class|class
name|CrashedAction
super|:
specifier|public
name|QWidgetAction
block|{
public|public:
DECL|function|CrashedAction
specifier|inline
name|CrashedAction
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QWidgetAction
argument_list|(
name|parent
argument_list|)
block|{ }
DECL|function|createWidget
specifier|virtual
name|QWidget
modifier|*
name|createWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
block|{
return|return
operator|new
name|QWidget
argument_list|(
name|parent
argument_list|)
return|;
block|}
block|}
class|;
end_class
begin_function
DECL|function|releaseWidgetCrash
name|void
name|tst_QWidgetAction
operator|::
name|releaseWidgetCrash
parameter_list|()
block|{
comment|// this should not crash!
name|QMainWindow
modifier|*
name|w
init|=
operator|new
name|QMainWindow
decl_stmt|;
name|QAction
modifier|*
name|a
init|=
operator|new
name|CrashedAction
argument_list|(
name|w
argument_list|)
decl_stmt|;
name|QMenu
modifier|*
name|menu
init|=
name|w
operator|->
name|menuBar
argument_list|()
operator|->
name|addMenu
argument_list|(
literal|"Test"
argument_list|)
decl_stmt|;
name|menu
operator|->
name|addAction
argument_list|(
literal|"foo"
argument_list|)
expr_stmt|;
name|menu
operator|->
name|addAction
argument_list|(
name|a
argument_list|)
expr_stmt|;
name|menu
operator|->
name|addAction
argument_list|(
literal|"bar"
argument_list|)
expr_stmt|;
operator|delete
name|w
expr_stmt|;
block|}
end_function
begin_macro
name|QTEST_MAIN
argument_list|(
argument|tst_QWidgetAction
argument_list|)
end_macro
begin_include
include|#
directive|include
file|"tst_qwidgetaction.moc"
end_include
end_unit
