begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOREEVENT_H
end_ifndef
begin_define
DECL|macro|QCOREEVENT_H
define|#
directive|define
name|QCOREEVENT_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qnamespace.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qbytearray.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qobjectdefs.h>
end_include
begin_function
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
parameter_list|(
name|Core
parameter_list|)
name|class
name|QEventPrivate
decl_stmt|;
name|class
name|Q_CORE_EXPORT
name|QEvent
comment|// event base class
decl_stmt|{     Q_GADGET     QDOC_PROPERTY(bool accepted READ isAccepted WRITE setAccepted
end_function
begin_macro
unit|)
name|Q_ENUMS
argument_list|(
argument|Type
argument_list|)
end_macro
begin_label
name|public
label|:
end_label
begin_enum
enum|enum
name|Type
block|{
comment|/*           If you get a strange compiler error on the line with None,           it's probably because you're also including X11 headers,           which #define the symbol None. Put the X11 includes after           the Qt includes to solve this problem.         */
name|None
init|=
literal|0
block|,
comment|// invalid event
name|Timer
init|=
literal|1
block|,
comment|// timer event
name|MouseButtonPress
init|=
literal|2
block|,
comment|// mouse button pressed
name|MouseButtonRelease
init|=
literal|3
block|,
comment|// mouse button released
name|MouseButtonDblClick
init|=
literal|4
block|,
comment|// mouse button double click
name|MouseMove
init|=
literal|5
block|,
comment|// mouse move
name|KeyPress
init|=
literal|6
block|,
comment|// key pressed
name|KeyRelease
init|=
literal|7
block|,
comment|// key released
name|FocusIn
init|=
literal|8
block|,
comment|// keyboard focus received
name|FocusOut
init|=
literal|9
block|,
comment|// keyboard focus lost
name|Enter
init|=
literal|10
block|,
comment|// mouse enters widget
name|Leave
init|=
literal|11
block|,
comment|// mouse leaves widget
name|Paint
init|=
literal|12
block|,
comment|// paint widget
name|Move
init|=
literal|13
block|,
comment|// move widget
name|Resize
init|=
literal|14
block|,
comment|// resize widget
name|Create
init|=
literal|15
block|,
comment|// after widget creation
name|Destroy
init|=
literal|16
block|,
comment|// during widget destruction
name|Show
init|=
literal|17
block|,
comment|// widget is shown
name|Hide
init|=
literal|18
block|,
comment|// widget is hidden
name|Close
init|=
literal|19
block|,
comment|// request to close widget
name|Quit
init|=
literal|20
block|,
comment|// request to quit application
name|ParentChange
init|=
literal|21
block|,
comment|// widget has been reparented
name|ParentAboutToChange
init|=
literal|131
block|,
comment|// sent just before the parent change is done
name|ThreadChange
init|=
literal|22
block|,
comment|// object has changed threads
name|WindowActivate
init|=
literal|24
block|,
comment|// window was activated
name|WindowDeactivate
init|=
literal|25
block|,
comment|// window was deactivated
name|ShowToParent
init|=
literal|26
block|,
comment|// widget is shown to parent
name|HideToParent
init|=
literal|27
block|,
comment|// widget is hidden to parent
name|Wheel
init|=
literal|31
block|,
comment|// wheel event
name|WindowTitleChange
init|=
literal|33
block|,
comment|// window title changed
name|WindowIconChange
init|=
literal|34
block|,
comment|// icon changed
name|ApplicationWindowIconChange
init|=
literal|35
block|,
comment|// application icon changed
name|ApplicationFontChange
init|=
literal|36
block|,
comment|// application font changed
name|ApplicationLayoutDirectionChange
init|=
literal|37
block|,
comment|// application layout direction changed
name|ApplicationPaletteChange
init|=
literal|38
block|,
comment|// application palette changed
name|PaletteChange
init|=
literal|39
block|,
comment|// widget palette changed
name|Clipboard
init|=
literal|40
block|,
comment|// internal clipboard event
name|Speech
init|=
literal|42
block|,
comment|// reserved for speech input
name|MetaCall
init|=
literal|43
block|,
comment|// meta call event
name|SockAct
init|=
literal|50
block|,
comment|// socket activation
name|WinEventAct
init|=
literal|132
block|,
comment|// win event activation
name|DeferredDelete
init|=
literal|52
block|,
comment|// deferred delete event
name|DragEnter
init|=
literal|60
block|,
comment|// drag moves into widget
name|DragMove
init|=
literal|61
block|,
comment|// drag moves in widget
name|DragLeave
init|=
literal|62
block|,
comment|// drag leaves or is cancelled
name|Drop
init|=
literal|63
block|,
comment|// actual drop
name|DragResponse
init|=
literal|64
block|,
comment|// drag accepted/rejected
name|ChildAdded
init|=
literal|68
block|,
comment|// new child widget
name|ChildPolished
init|=
literal|69
block|,
comment|// polished child widget
name|ChildRemoved
init|=
literal|71
block|,
comment|// deleted child widget
name|ShowWindowRequest
init|=
literal|73
block|,
comment|// widget's window should be mapped
name|PolishRequest
init|=
literal|74
block|,
comment|// widget should be polished
name|Polish
init|=
literal|75
block|,
comment|// widget is polished
name|LayoutRequest
init|=
literal|76
block|,
comment|// widget should be relayouted
name|UpdateRequest
init|=
literal|77
block|,
comment|// widget should be repainted
name|UpdateLater
init|=
literal|78
block|,
comment|// request update() later
name|EmbeddingControl
init|=
literal|79
block|,
comment|// ActiveX embedding
name|ActivateControl
init|=
literal|80
block|,
comment|// ActiveX activation
name|DeactivateControl
init|=
literal|81
block|,
comment|// ActiveX deactivation
name|ContextMenu
init|=
literal|82
block|,
comment|// context popup menu
name|InputMethod
init|=
literal|83
block|,
comment|// input method
name|AccessibilityPrepare
init|=
literal|86
block|,
comment|// accessibility information is requested
name|TabletMove
init|=
literal|87
block|,
comment|// Wacom tablet event
name|LocaleChange
init|=
literal|88
block|,
comment|// the system locale changed
name|LanguageChange
init|=
literal|89
block|,
comment|// the application language changed
name|LayoutDirectionChange
init|=
literal|90
block|,
comment|// the layout direction changed
name|Style
init|=
literal|91
block|,
comment|// internal style event
name|TabletPress
init|=
literal|92
block|,
comment|// tablet press
name|TabletRelease
init|=
literal|93
block|,
comment|// tablet release
name|OkRequest
init|=
literal|94
block|,
comment|// CE (Ok) button pressed
name|HelpRequest
init|=
literal|95
block|,
comment|// CE (?)  button pressed
name|IconDrag
init|=
literal|96
block|,
comment|// proxy icon dragged
name|FontChange
init|=
literal|97
block|,
comment|// font has changed
name|EnabledChange
init|=
literal|98
block|,
comment|// enabled state has changed
name|ActivationChange
init|=
literal|99
block|,
comment|// window activation has changed
name|StyleChange
init|=
literal|100
block|,
comment|// style has changed
name|IconTextChange
init|=
literal|101
block|,
comment|// icon text has changed
name|ModifiedChange
init|=
literal|102
block|,
comment|// modified state has changed
name|MouseTrackingChange
init|=
literal|109
block|,
comment|// mouse tracking state has changed
name|WindowBlocked
init|=
literal|103
block|,
comment|// window is about to be blocked modally
name|WindowUnblocked
init|=
literal|104
block|,
comment|// windows modal blocking has ended
name|WindowStateChange
init|=
literal|105
block|,
name|ToolTip
init|=
literal|110
block|,
name|WhatsThis
init|=
literal|111
block|,
name|StatusTip
init|=
literal|112
block|,
name|ActionChanged
init|=
literal|113
block|,
name|ActionAdded
init|=
literal|114
block|,
name|ActionRemoved
init|=
literal|115
block|,
name|FileOpen
init|=
literal|116
block|,
comment|// file open request
name|Shortcut
init|=
literal|117
block|,
comment|// shortcut triggered
name|ShortcutOverride
init|=
literal|51
block|,
comment|// shortcut override request
name|WhatsThisClicked
init|=
literal|118
block|,
name|ToolBarChange
init|=
literal|120
block|,
comment|// toolbar visibility toggled
name|ApplicationActivate
init|=
literal|121
block|,
comment|// application has been changed to active
name|ApplicationActivated
init|=
name|ApplicationActivate
block|,
comment|// deprecated
name|ApplicationDeactivate
init|=
literal|122
block|,
comment|// application has been changed to inactive
name|ApplicationDeactivated
init|=
name|ApplicationDeactivate
block|,
comment|// deprecated
name|QueryWhatsThis
init|=
literal|123
block|,
comment|// query what's this widget help
name|EnterWhatsThisMode
init|=
literal|124
block|,
name|LeaveWhatsThisMode
init|=
literal|125
block|,
name|ZOrderChange
init|=
literal|126
block|,
comment|// child widget has had its z-order changed
name|HoverEnter
init|=
literal|127
block|,
comment|// mouse cursor enters a hover widget
name|HoverLeave
init|=
literal|128
block|,
comment|// mouse cursor leaves a hover widget
name|HoverMove
init|=
literal|129
block|,
comment|// mouse cursor move inside a hover widget
name|AccessibilityHelp
init|=
literal|119
block|,
comment|// accessibility help text request
name|AccessibilityDescription
init|=
literal|130
block|,
comment|// accessibility description text request
comment|// last event id used = 132
ifdef|#
directive|ifdef
name|QT_KEYPAD_NAVIGATION
name|EnterEditFocus
init|=
literal|150
block|,
comment|// enter edit mode in keypad navigation
name|LeaveEditFocus
init|=
literal|151
block|,
comment|// enter edit mode in keypad navigation
endif|#
directive|endif
name|AcceptDropsChange
init|=
literal|152
block|,
name|MenubarUpdated
init|=
literal|153
block|,
comment|// Support event for Q3MainWindow, which needs to
comment|// knwow when QMenubar is updated.
name|ZeroTimerEvent
init|=
literal|154
block|,
comment|// Used for Windows Zero timer events
name|GraphicsSceneMouseMove
init|=
literal|155
block|,
comment|// GraphicsView
name|GraphicsSceneMousePress
init|=
literal|156
block|,
name|GraphicsSceneMouseRelease
init|=
literal|157
block|,
name|GraphicsSceneMouseDoubleClick
init|=
literal|158
block|,
name|GraphicsSceneContextMenu
init|=
literal|159
block|,
name|GraphicsSceneHoverEnter
init|=
literal|160
block|,
name|GraphicsSceneHoverMove
init|=
literal|161
block|,
name|GraphicsSceneHoverLeave
init|=
literal|162
block|,
name|GraphicsSceneHelp
init|=
literal|163
block|,
name|GraphicsSceneDragEnter
init|=
literal|164
block|,
name|GraphicsSceneDragMove
init|=
literal|165
block|,
name|GraphicsSceneDragLeave
init|=
literal|166
block|,
name|GraphicsSceneDrop
init|=
literal|167
block|,
name|GraphicsSceneWheel
init|=
literal|168
block|,
name|KeyboardLayoutChange
init|=
literal|169
block|,
comment|// keyboard layout changed
name|DynamicPropertyChange
init|=
literal|170
block|,
comment|// A dynamic property was changed through setProperty/property
name|TabletEnterProximity
init|=
literal|171
block|,
name|TabletLeaveProximity
init|=
literal|172
block|,
name|NonClientAreaMouseMove
init|=
literal|173
block|,
name|NonClientAreaMouseButtonPress
init|=
literal|174
block|,
name|NonClientAreaMouseButtonRelease
init|=
literal|175
block|,
name|NonClientAreaMouseButtonDblClick
init|=
literal|176
block|,
name|MacSizeChange
init|=
literal|177
block|,
comment|// when the Qt::WA_Mac{Normal,Small,Mini}Size changes
name|ContentsRectChange
init|=
literal|178
block|,
comment|// sent by QWidget::setContentsMargins (internal)
name|MacGLWindowChange
init|=
literal|179
block|,
comment|// Internal! the window of the GLWidget has changed
name|FutureCallOut
init|=
literal|180
block|,
name|GraphicsSceneResize
init|=
literal|181
block|,
name|GraphicsSceneMove
init|=
literal|182
block|,
name|CursorChange
init|=
literal|183
block|,
name|ToolTipChange
init|=
literal|184
block|,
name|NetworkReplyUpdated
init|=
literal|185
block|,
comment|// Internal for QNetworkReply
name|GrabMouse
init|=
literal|186
block|,
name|UngrabMouse
init|=
literal|187
block|,
name|GrabKeyboard
init|=
literal|188
block|,
name|UngrabKeyboard
init|=
literal|189
block|,
name|MacGLClearDrawable
init|=
literal|191
block|,
comment|// Internal Cocoa, the window has changed, so we must clear
name|StateMachineSignal
init|=
literal|192
block|,
name|StateMachineWrapped
init|=
literal|193
block|,
name|TouchBegin
init|=
literal|194
block|,
name|TouchUpdate
init|=
literal|195
block|,
name|TouchEnd
init|=
literal|196
block|,
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
name|NativeGesture
init|=
literal|197
block|,
comment|// Internal for platform gesture support
endif|#
directive|endif
name|RequestSoftwareInputPanel
init|=
literal|199
block|,
name|CloseSoftwareInputPanel
init|=
literal|200
block|,
name|UpdateSoftKeys
init|=
literal|201
block|,
comment|// Internal for compressing soft key updates
name|WinIdChange
init|=
literal|203
block|,
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
name|Gesture
init|=
literal|198
block|,
name|GestureOverride
init|=
literal|202
block|,
endif|#
directive|endif
name|ScrollPrepare
init|=
literal|204
block|,
name|Scroll
init|=
literal|205
block|,
name|Map
init|=
literal|206
block|,
name|Unmap
init|=
literal|207
block|,
name|Expose
init|=
literal|208
block|,
name|InputMethodQuery
init|=
literal|209
block|,
name|OrientationChange
init|=
literal|210
block|,
comment|// Screen orientation has changed
comment|// 512 reserved for Qt Jambi's MetaCall event
comment|// 513 reserved for Qt Jambi's DeleteOnMainThread event
name|User
init|=
literal|1000
block|,
comment|// first user event id
name|MaxUser
init|=
literal|65535
comment|// last user event id
block|}
enum|;
end_enum
begin_macro
name|QEvent
argument_list|(
argument|Type type
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_expr_stmt
name|virtual
operator|~
name|QEvent
argument_list|()
expr_stmt|;
end_expr_stmt
begin_expr_stmt
specifier|inline
name|Type
name|type
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|Type
operator|>
operator|(
name|t
operator|)
return|;
block|}
end_expr_stmt
begin_expr_stmt
specifier|inline
name|bool
name|spontaneous
argument_list|()
specifier|const
block|{
return|return
name|spont
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|void
name|setAccepted
parameter_list|(
name|bool
name|accepted
parameter_list|)
block|{
name|m_accept
operator|=
name|accepted
expr_stmt|;
block|}
end_function
begin_expr_stmt
specifier|inline
name|bool
name|isAccepted
argument_list|()
specifier|const
block|{
return|return
name|m_accept
return|;
block|}
end_expr_stmt
begin_function
specifier|inline
name|void
name|accept
parameter_list|()
block|{
name|m_accept
operator|=
name|true
expr_stmt|;
block|}
end_function
begin_function
specifier|inline
name|void
name|ignore
parameter_list|()
block|{
name|m_accept
operator|=
name|false
expr_stmt|;
block|}
end_function
begin_function_decl
specifier|static
name|int
name|registerEventType
parameter_list|(
name|int
name|hint
init|=
operator|-
literal|1
parameter_list|)
function_decl|;
end_function_decl
begin_label
name|protected
label|:
end_label
begin_decl_stmt
name|QEventPrivate
modifier|*
name|d
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|ushort
name|t
decl_stmt|;
end_decl_stmt
begin_label
name|private
label|:
end_label
begin_decl_stmt
name|ushort
name|posted
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|ushort
name|spont
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|ushort
name|m_accept
range|:
literal|1
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|ushort
name|reserved
range|:
literal|13
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QCoreApplication
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QCoreApplicationPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QThreadData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QApplication
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QApplicationPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|Q3AccelManager
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QShortcutMap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QETWidget
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QGraphicsView
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QGraphicsViewPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QGraphicsScene
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|friend
name|class
name|QGraphicsScenePrivate
decl_stmt|;
end_decl_stmt
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_GESTURES
end_ifndef
begin_decl_stmt
name|friend
name|class
name|QGestureManager
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
unit|};
name|class
name|Q_CORE_EXPORT
name|QTimerEvent
range|:
name|public
name|QEvent
block|{
name|public
operator|:
name|QTimerEvent
argument_list|(
argument|int timerId
argument_list|)
block|;
operator|~
name|QTimerEvent
argument_list|()
block|;
name|int
name|timerId
argument_list|()
specifier|const
block|{
return|return
name|id
return|;
block|}
name|protected
operator|:
name|int
name|id
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QObject
name|class
name|QObject
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QChildEvent
range|:
name|public
name|QEvent
block|{
name|public
operator|:
name|QChildEvent
argument_list|(
argument|Type type
argument_list|,
argument|QObject *child
argument_list|)
block|;
operator|~
name|QChildEvent
argument_list|()
block|;
name|QObject
operator|*
name|child
argument_list|()
specifier|const
block|{
return|return
name|c
return|;
block|}
name|bool
name|added
argument_list|()
specifier|const
block|{
return|return
name|type
argument_list|()
operator|==
name|ChildAdded
return|;
block|}
name|bool
name|polished
argument_list|()
specifier|const
block|{
return|return
name|type
argument_list|()
operator|==
name|ChildPolished
return|;
block|}
name|bool
name|removed
argument_list|()
specifier|const
block|{
return|return
name|type
argument_list|()
operator|==
name|ChildRemoved
return|;
block|}
name|protected
operator|:
name|QObject
operator|*
name|c
block|; }
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_CORE_EXPORT
name|QDynamicPropertyChangeEvent
range|:
name|public
name|QEvent
block|{
name|public
operator|:
name|QDynamicPropertyChangeEvent
argument_list|(
specifier|const
name|QByteArray
operator|&
name|name
argument_list|)
block|;
operator|~
name|QDynamicPropertyChangeEvent
argument_list|()
block|;
specifier|inline
name|QByteArray
name|propertyName
argument_list|()
specifier|const
block|{
return|return
name|n
return|;
block|}
name|private
operator|:
name|QByteArray
name|n
block|; }
decl_stmt|;
end_decl_stmt
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCOREEVENT_H
end_comment
end_unit
