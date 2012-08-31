begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|<qinputmethod.h>
end_include
begin_include
include|#
directive|include
file|<private/qinputmethod_p.h>
end_include
begin_include
include|#
directive|include
file|<qguiapplication.h>
end_include
begin_include
include|#
directive|include
file|<qtimer.h>
end_include
begin_include
include|#
directive|include
file|<qpa/qplatforminputcontext_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*!     \internal */
end_comment
begin_constructor
DECL|function|QInputMethod
name|QInputMethod
operator|::
name|QInputMethod
parameter_list|()
member_init_list|:
name|QObject
argument_list|(
operator|*
operator|new
name|QInputMethodPrivate
argument_list|)
block|{
comment|// might be instantiated before QGuiApplication is fully done, need to connect later
name|QTimer
operator|::
name|singleShot
argument_list|(
literal|0
argument_list|,
name|this
argument_list|,
name|SLOT
argument_list|(
name|_q_connectFocusObject
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_constructor
begin_comment
comment|/*!     \internal */
end_comment
begin_destructor
DECL|function|~QInputMethod
name|QInputMethod
operator|::
name|~
name|QInputMethod
parameter_list|()
block|{ }
end_destructor
begin_comment
comment|/*!     \class QInputMethod     \brief The QInputMethod class provides access to the active text input method.     \inmodule QtGui      QInputMethod is used by the text editors for integrating to the platform text input     methods and more commonly by application views for querying various text input method-related     information like virtual keyboard visibility and keyboard dimensions.      Qt Quick also provides access to QInputMethod in QML through \l{QmlGlobalQtObject}{Qt global object}     as \c Qt.inputMethod property. */
end_comment
begin_comment
comment|/*!     \property QInputMethod::inputItem     \brief Focused item that accepts text input     \obsolete      Input item is set and unset by the focused window. In QML Scene Graph this is done by     QQuickCanvas and the input item is either TextInput or TextEdit element. Any QObject can     behave as an input item as long as it responds to QInputMethodQueryEvent and QInputMethodEvent     events sent by the input methods.      \sa inputItemTransform, inputWindow, QInputMethodQueryEvent, QInputMethodEvent */
end_comment
begin_function
DECL|function|inputItem
name|QObject
modifier|*
name|QInputMethod
operator|::
name|inputItem
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QInputMethod
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|inputItem
operator|.
name|data
argument_list|()
return|;
block|}
end_function
begin_function
DECL|function|setInputItem
name|void
name|QInputMethod
operator|::
name|setInputItem
parameter_list|(
name|QObject
modifier|*
name|inputItem
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QInputMethod
argument_list|)
expr_stmt|;
name|d
operator|->
name|setInputItem
argument_list|(
name|inputItem
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Returns the currently focused window containing the input item.      \obsolete */
end_comment
begin_function
DECL|function|inputWindow
name|QWindow
modifier|*
name|QInputMethod
operator|::
name|inputWindow
parameter_list|()
specifier|const
block|{
return|return
name|qApp
operator|->
name|focusWindow
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Returns the transformation from input item coordinates to the window coordinates. */
end_comment
begin_function
DECL|function|inputItemTransform
name|QTransform
name|QInputMethod
operator|::
name|inputItemTransform
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QInputMethod
argument_list|)
expr_stmt|;
return|return
name|d
operator|->
name|inputItemTransform
return|;
block|}
end_function
begin_comment
comment|/*!     Sets the transformation from input item coordinates to the window coordinates.     Item transform needs to be updated by the focused window like QQuickCanvas whenever     item is moved inside the scene. */
end_comment
begin_function
DECL|function|setInputItemTransform
name|void
name|QInputMethod
operator|::
name|setInputItemTransform
parameter_list|(
specifier|const
name|QTransform
modifier|&
name|transform
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QInputMethod
argument_list|)
expr_stmt|;
if|if
condition|(
name|d
operator|->
name|inputItemTransform
operator|==
name|transform
condition|)
return|return;
name|d
operator|->
name|inputItemTransform
operator|=
name|transform
expr_stmt|;
emit|emit
name|cursorRectangleChanged
argument_list|()
emit|;
block|}
end_function
begin_comment
comment|/*!     \property QInputMethod::cursorRectangle     \brief Input item's cursor rectangle in window coordinates.      Cursor rectangle is often used by various text editing controls     like text prediction popups for following the text being typed. */
end_comment
begin_function
DECL|function|cursorRectangle
name|QRectF
name|QInputMethod
operator|::
name|cursorRectangle
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QInputMethod
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|d
operator|->
name|inputItem
condition|)
return|return
name|QRectF
argument_list|()
return|;
name|QInputMethodQueryEvent
name|query
argument_list|(
name|Qt
operator|::
name|ImCursorRectangle
argument_list|)
decl_stmt|;
name|QGuiApplication
operator|::
name|sendEvent
argument_list|(
name|d
operator|->
name|inputItem
operator|.
name|data
argument_list|()
argument_list|,
operator|&
name|query
argument_list|)
expr_stmt|;
name|QRectF
name|r
init|=
name|query
operator|.
name|value
argument_list|(
name|Qt
operator|::
name|ImCursorRectangle
argument_list|)
operator|.
name|toRectF
argument_list|()
decl_stmt|;
if|if
condition|(
operator|!
name|r
operator|.
name|isValid
argument_list|()
condition|)
return|return
name|QRectF
argument_list|()
return|;
return|return
name|d
operator|->
name|inputItemTransform
operator|.
name|mapRect
argument_list|(
name|r
argument_list|)
return|;
block|}
end_function
begin_comment
comment|/*!     \property QInputMethod::keyboardRectangle     \brief Virtual keyboard's geometry in window coordinates. */
end_comment
begin_function
DECL|function|keyboardRectangle
name|QRectF
name|QInputMethod
operator|::
name|keyboardRectangle
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QInputMethod
argument_list|)
expr_stmt|;
name|QPlatformInputContext
modifier|*
name|ic
init|=
name|d
operator|->
name|platformInputContext
argument_list|()
decl_stmt|;
if|if
condition|(
name|ic
condition|)
return|return
name|ic
operator|->
name|keyboardRect
argument_list|()
return|;
return|return
name|QRectF
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     Requests virtual keyboard to open. If the platform     doesn't provide virtual keyboard the visibility     remains false.      Normally applications should not need to call this     function, keyboard should automatically open when     the text editor gains focus. */
end_comment
begin_function
DECL|function|show
name|void
name|QInputMethod
operator|::
name|show
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QInputMethod
argument_list|)
expr_stmt|;
name|QPlatformInputContext
modifier|*
name|ic
init|=
name|d
operator|->
name|platformInputContext
argument_list|()
decl_stmt|;
if|if
condition|(
name|ic
condition|)
name|ic
operator|->
name|showInputPanel
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Requests virtual keyboard to close.      Normally applications should not need to call this function,     keyboard should automatically close when the text editor loses     focus, for example when the parent view is closed. */
end_comment
begin_function
DECL|function|hide
name|void
name|QInputMethod
operator|::
name|hide
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QInputMethod
argument_list|)
expr_stmt|;
name|QPlatformInputContext
modifier|*
name|ic
init|=
name|d
operator|->
name|platformInputContext
argument_list|()
decl_stmt|;
if|if
condition|(
name|ic
condition|)
name|ic
operator|->
name|hideInputPanel
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \fn bool QInputMethod::visible() const     \obsolete      Use isVisible() instead. */
end_comment
begin_comment
comment|/*!     \property QInputMethod::visible     \brief Virtual keyboard's visibility on the screen      Input method visibility remains false for devices     with no virtual keyboards.      \sa show(), hide() */
end_comment
begin_function
DECL|function|isVisible
name|bool
name|QInputMethod
operator|::
name|isVisible
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QInputMethod
argument_list|)
expr_stmt|;
name|QPlatformInputContext
modifier|*
name|ic
init|=
name|d
operator|->
name|platformInputContext
argument_list|()
decl_stmt|;
if|if
condition|(
name|ic
condition|)
return|return
name|ic
operator|->
name|isInputPanelVisible
argument_list|()
return|;
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     Controls the keyboard visibility. Equivalent     to calling show() and hide() functions.      \sa show(), hide() */
end_comment
begin_function
DECL|function|setVisible
name|void
name|QInputMethod
operator|::
name|setVisible
parameter_list|(
name|bool
name|visible
parameter_list|)
block|{
name|visible
condition|?
name|show
argument_list|()
else|:
name|hide
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     \property QInputMethod::animating     \brief True when the virtual keyboard is being opened or closed.      Animating is false when keyboard is fully open or closed.     When \c animating is \c true and \c visibility is \c true keyboard     is being opened. When \c animating is \c true and \c visibility is     false keyboard is being closed. */
end_comment
begin_function
DECL|function|isAnimating
name|bool
name|QInputMethod
operator|::
name|isAnimating
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QInputMethod
argument_list|)
expr_stmt|;
name|QPlatformInputContext
modifier|*
name|ic
init|=
name|d
operator|->
name|platformInputContext
argument_list|()
decl_stmt|;
if|if
condition|(
name|ic
condition|)
return|return
name|ic
operator|->
name|isAnimating
argument_list|()
return|;
return|return
literal|false
return|;
block|}
end_function
begin_comment
comment|/*!     \property QInputMethod::locale     \brief Current input locale. */
end_comment
begin_function
DECL|function|locale
name|QLocale
name|QInputMethod
operator|::
name|locale
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QInputMethod
argument_list|)
expr_stmt|;
name|QPlatformInputContext
modifier|*
name|ic
init|=
name|d
operator|->
name|platformInputContext
argument_list|()
decl_stmt|;
if|if
condition|(
name|ic
condition|)
return|return
name|ic
operator|->
name|locale
argument_list|()
return|;
return|return
name|QLocale
operator|::
name|c
argument_list|()
return|;
block|}
end_function
begin_comment
comment|/*!     \property QInputMethod::inputDirection     \brief Current input direction. */
end_comment
begin_function
DECL|function|inputDirection
name|Qt
operator|::
name|LayoutDirection
name|QInputMethod
operator|::
name|inputDirection
parameter_list|()
specifier|const
block|{
name|Q_D
argument_list|(
specifier|const
name|QInputMethod
argument_list|)
expr_stmt|;
name|QPlatformInputContext
modifier|*
name|ic
init|=
name|d
operator|->
name|platformInputContext
argument_list|()
decl_stmt|;
if|if
condition|(
name|ic
condition|)
return|return
name|ic
operator|->
name|inputDirection
argument_list|()
return|;
return|return
name|Qt
operator|::
name|LeftToRight
return|;
block|}
end_function
begin_comment
comment|/*!     Called by the input item to inform the platform input methods when there has been     state changes in editor's input method query attributes. When calling the function     \a queries parameter has to be used to tell what has changes, which input method     can use to make queries for attributes it's interested with QInputMethodQueryEvent.      In particular calling update whenever the cursor position changes is important as     that often causes other query attributes like surrounding text and text selection     to change as well. The attributes that often change together with cursor position     have been grouped in Qt::ImQueryInput value for convenience. */
end_comment
begin_function
DECL|function|update
name|void
name|QInputMethod
operator|::
name|update
parameter_list|(
name|Qt
operator|::
name|InputMethodQueries
name|queries
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QInputMethod
argument_list|)
expr_stmt|;
if|if
condition|(
name|queries
operator|&
name|Qt
operator|::
name|ImEnabled
condition|)
block|{
name|QObject
modifier|*
name|focus
init|=
name|qApp
operator|->
name|focusObject
argument_list|()
decl_stmt|;
name|bool
name|enabled
init|=
name|d
operator|->
name|objectAcceptsInputMethod
argument_list|(
name|focus
argument_list|)
decl_stmt|;
name|d
operator|->
name|setInputItem
argument_list|(
name|enabled
condition|?
name|focus
else|:
literal|0
argument_list|)
expr_stmt|;
name|QPlatformInputContextPrivate
operator|::
name|setInputMethodAccepted
argument_list|(
name|enabled
argument_list|)
expr_stmt|;
block|}
name|QPlatformInputContext
modifier|*
name|ic
init|=
name|d
operator|->
name|platformInputContext
argument_list|()
decl_stmt|;
if|if
condition|(
name|ic
condition|)
name|ic
operator|->
name|update
argument_list|(
name|queries
argument_list|)
expr_stmt|;
if|if
condition|(
name|queries
operator|&
name|Qt
operator|::
name|ImCursorRectangle
condition|)
emit|emit
name|cursorRectangleChanged
argument_list|()
emit|;
block|}
end_function
begin_comment
comment|/*!     Resets the input method state. For example, a text editor normally calls     this method before inserting a text to make widget ready to accept a text.      Input method resets automatically when the focused editor changes. */
end_comment
begin_function
DECL|function|reset
name|void
name|QInputMethod
operator|::
name|reset
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QInputMethod
argument_list|)
expr_stmt|;
name|QPlatformInputContext
modifier|*
name|ic
init|=
name|d
operator|->
name|platformInputContext
argument_list|()
decl_stmt|;
if|if
condition|(
name|ic
condition|)
name|ic
operator|->
name|reset
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Commits the word user is currently composing to the editor. The function is     mostly needed by the input methods with text prediction features and by the     methods where the script used for typing characters is different from the     script that actually gets appended to the editor. Any kind of action that     interrupts the text composing needs to flush the composing state by calling the     commit() function, for example when the cursor is moved elsewhere. */
end_comment
begin_function
DECL|function|commit
name|void
name|QInputMethod
operator|::
name|commit
parameter_list|()
block|{
name|Q_D
argument_list|(
name|QInputMethod
argument_list|)
expr_stmt|;
name|QPlatformInputContext
modifier|*
name|ic
init|=
name|d
operator|->
name|platformInputContext
argument_list|()
decl_stmt|;
if|if
condition|(
name|ic
condition|)
name|ic
operator|->
name|commit
argument_list|()
expr_stmt|;
block|}
end_function
begin_comment
comment|/*!     Called by the input item when the word currently being composed is tapped by     the user. Input methods often use this information to offer more word     suggestions to the user. */
end_comment
begin_function
DECL|function|invokeAction
name|void
name|QInputMethod
operator|::
name|invokeAction
parameter_list|(
name|Action
name|a
parameter_list|,
name|int
name|cursorPosition
parameter_list|)
block|{
name|Q_D
argument_list|(
name|QInputMethod
argument_list|)
expr_stmt|;
name|QPlatformInputContext
modifier|*
name|ic
init|=
name|d
operator|->
name|platformInputContext
argument_list|()
decl_stmt|;
if|if
condition|(
name|ic
condition|)
name|ic
operator|->
name|invokeAction
argument_list|(
name|a
argument_list|,
name|cursorPosition
argument_list|)
expr_stmt|;
block|}
end_function
begin_comment
comment|// temporary handlers for updating focus item based on application focus
end_comment
begin_function
DECL|function|_q_connectFocusObject
name|void
name|QInputMethodPrivate
operator|::
name|_q_connectFocusObject
parameter_list|()
block|{
name|Q_Q
argument_list|(
name|QInputMethod
argument_list|)
expr_stmt|;
name|QObject
operator|::
name|connect
argument_list|(
name|qApp
argument_list|,
name|SIGNAL
argument_list|(
name|focusObjectChanged
argument_list|(
name|QObject
operator|*
argument_list|)
argument_list|)
argument_list|,
name|q
argument_list|,
name|SLOT
argument_list|(
name|_q_checkFocusObject
argument_list|(
name|QObject
operator|*
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|_q_checkFocusObject
argument_list|(
name|qApp
operator|->
name|focusObject
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|_q_checkFocusObject
name|void
name|QInputMethodPrivate
operator|::
name|_q_checkFocusObject
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|)
block|{
name|bool
name|enabled
init|=
name|objectAcceptsInputMethod
argument_list|(
name|object
argument_list|)
decl_stmt|;
name|setInputItem
argument_list|(
name|enabled
condition|?
name|object
else|:
literal|0
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|objectAcceptsInputMethod
name|bool
name|QInputMethodPrivate
operator|::
name|objectAcceptsInputMethod
parameter_list|(
name|QObject
modifier|*
name|object
parameter_list|)
block|{
name|bool
name|enabled
init|=
literal|false
decl_stmt|;
if|if
condition|(
name|object
condition|)
block|{
name|QInputMethodQueryEvent
name|query
argument_list|(
name|Qt
operator|::
name|ImEnabled
argument_list|)
decl_stmt|;
name|QGuiApplication
operator|::
name|sendEvent
argument_list|(
name|object
argument_list|,
operator|&
name|query
argument_list|)
expr_stmt|;
name|enabled
operator|=
name|query
operator|.
name|value
argument_list|(
name|Qt
operator|::
name|ImEnabled
argument_list|)
operator|.
name|toBool
argument_list|()
expr_stmt|;
block|}
return|return
name|enabled
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_include
include|#
directive|include
file|"moc_qinputmethod.cpp"
end_include
end_unit
