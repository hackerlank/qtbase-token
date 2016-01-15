begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtWidgets module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qwidgetaction.h"
end_include
begin_include
include|#
directive|include
file|"qdebug.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_ACTION
end_ifndef
begin_include
include|#
directive|include
file|"qwidgetaction_p.h"
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \class QWidgetAction     \since 4.2     \brief The QWidgetAction class extends QAction by an interface     for inserting custom widgets into action based containers, such     as toolbars.      \ingroup mainwindow-classes     \inmodule QtWidgets      Most actions in an application are represented as items in menus or     buttons in toolbars. However sometimes more complex widgets are     necessary. For example a zoom action in a word processor may be     realized using a QComboBox in a QToolBar, presenting a range     of different zoom levels. QToolBar provides QToolBar::insertWidget()     as convenience function for inserting a single widget.     However if you want to implement an action that uses custom     widgets for visualization in multiple containers then you have to     subclass QWidgetAction.      If a QWidgetAction is added for example to a QToolBar then     QWidgetAction::createWidget() is called. Reimplementations of that     function should create a new custom widget with the specified parent.      If the action is removed from a container widget then     QWidgetAction::deleteWidget() is called with the previously created custom     widget as argument. The default implementation hides the widget and deletes     it using QObject::deleteLater().      If you have only one single custom widget then you can set it as default     widget using setDefaultWidget(). That widget will then be used if the     action is added to a QToolBar, or in general to an action container that     supports QWidgetAction. If a QWidgetAction with only a default widget is     added to two toolbars at the same time then the default widget is shown     only in the first toolbar the action was added to. QWidgetAction takes     over ownership of the default widget.      Note that it is up to the widget to activate the action, for example by     reimplementing mouse event handlers and calling QAction::trigger().      \b {OS X}: If you add a widget to a menu in the application's menu     bar on OS X, the widget will be added and it will function but with some     limitations:     \list 1         \li The widget is reparented away from the QMenu to the native menu             view. If you show the menu in some other place (e.g. as a popup menu),             the widget will not be there.         \li Focus/Keyboard handling of the widget is not possible.         \li Due to Apple's design, mouse tracking on the widget currently does             not work.         \li Connecting the triggered() signal to a slot that opens a modal             dialog will cause a crash in Mac OS X 10.4 (known bug acknowledged             by Apple), a workaround is to use a QueuedConnection instead of a             DirectConnection.     \endlist      \sa QAction, QActionGroup, QWidget */
end_comment
begin_comment
comment|/*!     Constructs an action with \a parent. */
end_comment
begin_constructor
DECL|function|QWidgetAction
name|QWidgetAction
operator|::
name|QWidgetAction
parameter_list|(
name|QObject
modifier|*
name|parent
parameter_list|)
member_init_list|:
name|QAction
argument_list|(
operator|*
operator|(
operator|new
name|QWidgetActionPrivate
operator|)
argument_list|,
name|parent
argument_list|)
block|{ }
end_constructor
begin_comment
comment|/*!     Destroys the object and frees allocated resources. */
end_comment
begin_destructor
DECL|function|~QWidgetAction
name|QWidgetAction
operator|::
name|~
name|QWidgetAction
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QWidgetAction
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|d
operator|->
name|createdWidgets
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|disconnect
argument_list|(
name|d
operator|->
name|createdWidgets
operator|.
name|at
argument_list|(
name|i
argument_list|)
argument_list|,
name|SIGNAL
argument_list|(
name|destroyed
argument_list|(
name|QObject
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|_q_widgetDestroyed
argument_list|(
name|QObject
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|QList
argument_list|<
name|QWidget
modifier|*
argument_list|>
name|widgetsToDelete
init|=
name|d
operator|->
name|createdWidgets
decl_stmt|;
name|d
operator|->
name|createdWidgets
operator|.
name|clear
argument_list|()
expr_stmt|;
name|qDeleteAll
argument_list|(
name|widgetsToDelete
argument_list|)
expr_stmt|;
operator|delete
name|d
operator|->
name|defaultWidget
expr_stmt|;
block|}
end_destructor
begin_comment
comment|/*!     Sets \a widget to be the default widget. The ownership is     transferred to QWidgetAction. Unless createWidget() is     reimplemented by a subclass to return a new widget the default     widget is used when a container widget requests a widget through     requestWidget(). */
end_comment
begin_function
DECL|function|setDefaultWidget
name|void
name|QWidgetAction
operator|::
name|setDefaultWidget
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWidgetAction
argument_list|)
expr_stmt|;
if|if
condition|(
name|widget
operator|==
name|d
operator|->
name|defaultWidget
operator|||
name|d
operator|->
name|defaultWidgetInUse
condition|)
return|return;
operator|delete
name|d
operator|->
name|defaultWidget
expr_stmt|;
name|d
operator|->
name|defaultWidget
operator|=
name|widget
expr_stmt|;
if|if
condition|(
operator|!
name|widget
condition|)
return|return;
name|setVisible
argument_list|(
operator|!
operator|(
name|widget
operator|->
name|isHidden
argument_list|()
operator|&&
name|widget
operator|->
name|testAttribute
argument_list|(
name|Qt
operator|::
name|WA_WState_ExplicitShowHide
argument_list|)
operator|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|defaultWidget
operator|->
name|hide
argument_list|()
expr_stmt|;
name|d
operator|->
name|defaultWidget
operator|->
name|setParent
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|d
operator|->
name|defaultWidgetInUse
operator|=
literal|false
expr_stmt|;
if|if
condition|(
operator|!
name|isEnabled
argument_list|()
condition|)
name|d
operator|->
name|defaultWidget
operator|->
name|setEnabled
argument_list|(
literal|false
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the default widget. */
end_comment
begin_function
DECL|function|defaultWidget
name|QWidget
modifier|*
name|QWidgetAction
operator|::
name|defaultWidget
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWidgetAction
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|defaultWidget
return|;
block|}
end_function
begin_comment
comment|/*!     Returns a widget that represents the action, with the given \a     parent.      Container widgets that support actions can call this function to     request a widget as visual representation of the action.      \sa releaseWidget(), createWidget(), defaultWidget() */
end_comment
begin_function
DECL|function|requestWidget
name|QWidget
modifier|*
name|QWidgetAction
operator|::
name|requestWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWidgetAction
argument_list|)
expr_stmt|;
name|QWidget
modifier|*
name|w
init|=
name|createWidget
argument_list|(
name|parent
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|w
condition|)
block|{
if|if
condition|(
name|d
operator|->
name|defaultWidgetInUse
operator|||
operator|!
name|d
operator|->
name|defaultWidget
condition|)
return|return
literal|0
return|;
name|d
operator|->
name|defaultWidget
operator|->
name|setParent
argument_list|(
name|parent
argument_list|)
expr_stmt|;
name|d
operator|->
name|defaultWidgetInUse
operator|=
literal|true
expr_stmt|;
return|return
name|d
operator|->
name|defaultWidget
return|;
block|}
name|connect
argument_list|(
name|w
argument_list|,
name|SIGNAL
argument_list|(
name|destroyed
argument_list|(
name|QObject
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|_q_widgetDestroyed
argument_list|(
name|QObject
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|createdWidgets
operator|.
name|append
argument_list|(
name|w
argument_list|)
expr_stmt|;
return|return
name|w
return|;
block|}
end_function
begin_comment
comment|/*!     Releases the specified \a widget.      Container widgets that support actions call this function when a widget     action is removed.      \sa requestWidget(), deleteWidget(), defaultWidget() */
end_comment
begin_function
DECL|function|releaseWidget
name|void
name|QWidgetAction
operator|::
name|releaseWidget
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWidgetAction
argument_list|)
expr_stmt|;
if|if
condition|(
name|widget
operator|==
name|d
operator|->
name|defaultWidget
condition|)
block|{
name|d
operator|->
name|defaultWidget
operator|->
name|hide
argument_list|()
expr_stmt|;
name|d
operator|->
name|defaultWidget
operator|->
name|setParent
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|d
operator|->
name|defaultWidgetInUse
operator|=
literal|false
expr_stmt|;
return|return;
block|}
if|if
condition|(
operator|!
name|d
operator|->
name|createdWidgets
operator|.
name|contains
argument_list|(
name|widget
argument_list|)
condition|)
return|return;
name|disconnect
argument_list|(
name|widget
argument_list|,
name|SIGNAL
argument_list|(
name|destroyed
argument_list|(
name|QObject
operator|*
argument_list|)
argument_list|)
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|_q_widgetDestroyed
argument_list|(
name|QObject
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|d
operator|->
name|createdWidgets
operator|.
name|removeAll
argument_list|(
name|widget
argument_list|)
expr_stmt|;
name|deleteWidget
argument_list|(
name|widget
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \reimp */
end_comment
begin_function
DECL|function|event
name|bool
name|QWidgetAction
operator|::
name|event
parameter_list|(
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QWidgetAction
argument_list|)
expr_stmt|;
if|if
condition|(
name|event
operator|->
name|type
argument_list|()
operator|==
name|QEvent
operator|::
name|ActionChanged
condition|)
block|{
if|if
condition|(
name|d
operator|->
name|defaultWidget
condition|)
name|d
operator|->
name|defaultWidget
operator|->
name|setEnabled
argument_list|(
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
for|for
control|(
name|int
name|i
init|=
literal|0
init|;
name|i
operator|<
name|d
operator|->
name|createdWidgets
operator|.
name|count
argument_list|()
condition|;
operator|++
name|i
control|)
name|d
operator|->
name|createdWidgets
operator|.
name|at
argument_list|(
name|i
argument_list|)
operator|->
name|setEnabled
argument_list|(
name|isEnabled
argument_list|()
argument_list|)
expr_stmt|;
block|}
return|return
name|QAction
operator|::
name|event
argument_list|(
name|event
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \reimp  */
end_comment
begin_function
DECL|function|eventFilter
name|bool
name|QWidgetAction
operator|::
name|eventFilter
parameter_list|(
name|QObject
modifier|*
name|obj
parameter_list|,
name|QEvent
modifier|*
name|event
parameter_list|)
block|{
return|return
name|QAction
operator|::
name|eventFilter
argument_list|(
name|obj
argument_list|,
name|event
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     This function is called whenever the action is added to a container widget     that supports custom widgets. If you don't want a custom widget to be     used as representation of the action in the specified \a parent widget then     0 should be returned.      \sa deleteWidget() */
end_comment
begin_function
DECL|function|createWidget
name|QWidget
modifier|*
name|QWidgetAction
operator|::
name|createWidget
parameter_list|(
name|QWidget
modifier|*
name|parent
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
argument|parent
argument_list|)
return|return
literal|0
return|;
block|}
end_function
begin_comment
comment|/*!     This function is called whenever the action is removed from a     container widget that displays the action using a custom \a     widget previously created using createWidget(). The default     implementation hides the \a widget and schedules it for deletion     using QObject::deleteLater().      \sa createWidget() */
end_comment
begin_function
DECL|function|deleteWidget
name|void
name|QWidgetAction
operator|::
name|deleteWidget
parameter_list|(
name|QWidget
modifier|*
name|widget
parameter_list|)
block|{
name|widget
operator|->
name|hide
argument_list|()
expr_stmt|;
name|widget
operator|->
name|deleteLater
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the list of widgets that have been using createWidget() and     are currently in use by widgets the action has been added to. */
end_comment
begin_function
DECL|function|createdWidgets
name|QList
argument_list|<
name|QWidget
modifier|*
argument_list|>
name|QWidgetAction
operator|::
name|createdWidgets
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QWidgetAction
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|createdWidgets
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"moc_qwidgetaction.cpp"
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_ACTION
end_comment
end_unit
