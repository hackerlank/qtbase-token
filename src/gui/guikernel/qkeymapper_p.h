begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QKEYMAPPER_P_H
end_ifndef
begin_define
DECL|macro|QKEYMAPPER_P_H
define|#
directive|define
name|QKEYMAPPER_P_H
end_define
begin_comment
comment|//
end_comment
begin_comment
comment|//  W A R N I N G
end_comment
begin_comment
comment|//  -------------
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// This file is not part of the Qt API.  It exists purely as an
end_comment
begin_comment
comment|// implementation detail.  This header file may change from version to
end_comment
begin_comment
comment|// version without notice, or even be removed.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// We mean it.
end_comment
begin_comment
comment|//
end_comment
begin_include
include|#
directive|include
file|<qobject.h>
end_include
begin_include
include|#
directive|include
file|<private/qobject_p.h>
end_include
begin_include
include|#
directive|include
file|<qkeysequence.h>
end_include
begin_include
include|#
directive|include
file|<qlist.h>
end_include
begin_include
include|#
directive|include
file|<qlocale.h>
end_include
begin_include
include|#
directive|include
file|<qevent.h>
end_include
begin_include
include|#
directive|include
file|<qhash.h>
end_include
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_WS_MAC64
argument_list|)
end_if
begin_include
include|#
directive|include
file|<private/qt_mac_p.h>
end_include
begin_endif
endif|#
directive|endif
end_endif
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QKeyMapperPrivate
name|class
name|QKeyMapperPrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QKeyMapper
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|public
operator|:
name|explicit
name|QKeyMapper
argument_list|()
block|;
operator|~
name|QKeyMapper
argument_list|()
block|;
specifier|static
name|QKeyMapper
operator|*
name|instance
argument_list|()
block|;
specifier|static
name|void
name|changeKeyboard
argument_list|()
block|;
ifndef|#
directive|ifndef
name|Q_WS_QPA
specifier|static
name|bool
name|sendKeyEvent
argument_list|(
argument|QWidget *widget
argument_list|,
argument|bool grab
argument_list|,
argument|QEvent::Type type
argument_list|,
argument|int code
argument_list|,
argument|Qt::KeyboardModifiers modifiers
argument_list|,
argument|const QString&text
argument_list|,
argument|bool autorepeat
argument_list|,
argument|int count
argument_list|,
argument|quint32 nativeScanCode
argument_list|,
argument|quint32 nativeVirtualKey
argument_list|,
argument|quint32 nativeModifiers
argument_list|,
argument|bool *unusedExceptForCocoa =
literal|0
argument_list|)
block|;
endif|#
directive|endif
specifier|static
name|QList
operator|<
name|int
operator|>
name|possibleKeys
argument_list|(
name|QKeyEvent
operator|*
name|e
argument_list|)
block|;
name|private
operator|:
name|friend
name|QKeyMapperPrivate
operator|*
name|qt_keymapper_private
argument_list|()
block|;
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QKeyMapper
argument_list|)
name|Q_DISABLE_COPY
argument_list|(
argument|QKeyMapper
argument_list|)
block|}
decl_stmt|;
end_decl_stmt
begin_if
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
end_if
begin_enum
DECL|enum|WindowsNativeModifiers
enum|enum
name|WindowsNativeModifiers
block|{
DECL|enumerator|ShiftLeft
name|ShiftLeft
init|=
literal|0x00000001
block|,
DECL|enumerator|ControlLeft
name|ControlLeft
init|=
literal|0x00000002
block|,
DECL|enumerator|AltLeft
name|AltLeft
init|=
literal|0x00000004
block|,
DECL|enumerator|MetaLeft
name|MetaLeft
init|=
literal|0x00000008
block|,
DECL|enumerator|ShiftRight
name|ShiftRight
init|=
literal|0x00000010
block|,
DECL|enumerator|ControlRight
name|ControlRight
init|=
literal|0x00000020
block|,
DECL|enumerator|AltRight
name|AltRight
init|=
literal|0x00000040
block|,
DECL|enumerator|MetaRight
name|MetaRight
init|=
literal|0x00000080
block|,
DECL|enumerator|CapsLock
name|CapsLock
init|=
literal|0x00000100
block|,
DECL|enumerator|NumLock
name|NumLock
init|=
literal|0x00000200
block|,
DECL|enumerator|ScrollLock
name|ScrollLock
init|=
literal|0x00000400
block|,
DECL|enumerator|ExtendedKey
name|ExtendedKey
init|=
literal|0x01000000
block|,
comment|// Convenience mappings
DECL|enumerator|ShiftAny
name|ShiftAny
init|=
literal|0x00000011
block|,
DECL|enumerator|ControlAny
name|ControlAny
init|=
literal|0x00000022
block|,
DECL|enumerator|AltAny
name|AltAny
init|=
literal|0x00000044
block|,
DECL|enumerator|MetaAny
name|MetaAny
init|=
literal|0x00000088
block|,
DECL|enumerator|LockAny
name|LockAny
init|=
literal|0x00000700
block|}
enum|;
end_enum
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|tagMSG
argument_list|)
end_if
begin_typedef
DECL|typedef|MSG
typedef|typedef
name|struct
name|tagMSG
name|MSG
typedef|;
end_typedef
begin_endif
endif|#
directive|endif
end_endif
begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|Q_WS_MAC
argument_list|)
end_elif
begin_expr_stmt
name|QT_BEGIN_INCLUDE_NAMESPACE
include|#
directive|include
file|<private/qt_mac_p.h>
name|QT_END_INCLUDE_NAMESPACE
elif|#
directive|elif
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
name|QT_BEGIN_INCLUDE_NAMESPACE
end_expr_stmt
begin_typedef
typedef|typedef
name|ulong
name|XID
typedef|;
end_typedef
begin_typedef
typedef|typedef
name|XID
name|KeySym
typedef|;
end_typedef
begin_macro
name|QT_END_INCLUDE_NAMESPACE
end_macro
begin_struct
struct|struct
name|QXCoreDesc
block|{
name|int
name|min_keycode
decl_stmt|;
name|int
name|max_keycode
decl_stmt|;
name|int
name|keysyms_per_keycode
decl_stmt|;
name|KeySym
modifier|*
name|keysyms
decl_stmt|;
name|uchar
name|mode_switch
decl_stmt|;
name|uchar
name|num_lock
decl_stmt|;
name|KeySym
name|lock_meaning
decl_stmt|;
block|}
struct|;
end_struct
begin_endif
endif|#
directive|endif
end_endif
begin_struct_decl
struct_decl|struct
name|KeyboardLayoutItem
struct_decl|;
end_struct_decl
begin_typedef
DECL|typedef|TISInputSourceRef
typedef|typedef
name|struct
name|__TISInputSource
modifier|*
name|TISInputSourceRef
typedef|;
end_typedef
begin_decl_stmt
DECL|variable|QKeyEvent
name|class
name|QKeyEvent
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QKeyMapperPrivate
range|:
name|public
name|QObjectPrivate
block|{
name|Q_DECLARE_PUBLIC
argument_list|(
argument|QKeyMapper
argument_list|)
name|public
operator|:
name|QKeyMapperPrivate
argument_list|()
block|;
operator|~
name|QKeyMapperPrivate
argument_list|()
block|;
name|void
name|clearMappings
argument_list|()
block|;
name|QList
operator|<
name|int
operator|>
name|possibleKeys
argument_list|(
name|QKeyEvent
operator|*
name|e
argument_list|)
block|;
name|QLocale
name|keyboardInputLocale
block|;
name|Qt
operator|::
name|LayoutDirection
name|keyboardInputDirection
block|;
if|#
directive|if
name|defined
argument_list|(
name|Q_OS_WIN
argument_list|)
name|void
name|clearRecordedKeys
argument_list|()
block|;
name|void
name|updateKeyMap
argument_list|(
specifier|const
name|MSG
operator|&
name|msg
argument_list|)
block|;
name|bool
name|translateKeyEvent
argument_list|(
argument|QWidget *receiver
argument_list|,
argument|const MSG&msg
argument_list|,
argument|bool grab
argument_list|)
block|;
name|void
name|updatePossibleKeyCodes
argument_list|(
argument|unsigned char *kbdBuffer
argument_list|,
argument|quint32 scancode
argument_list|,
argument|quint32 vk_key
argument_list|)
block|;
name|bool
name|isADeadKey
argument_list|(
argument|unsigned int vk_key
argument_list|,
argument|unsigned int modifiers
argument_list|)
block|;
name|void
name|deleteLayouts
argument_list|()
block|;
name|KeyboardLayoutItem
operator|*
name|keyLayout
index|[
literal|256
index|]
block|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_WS_X11
argument_list|)
name|QList
operator|<
name|int
operator|>
name|possibleKeysXKB
argument_list|(
name|QKeyEvent
operator|*
name|event
argument_list|)
block|;
name|QList
operator|<
name|int
operator|>
name|possibleKeysCore
argument_list|(
name|QKeyEvent
operator|*
name|event
argument_list|)
block|;
name|bool
name|translateKeyEventInternal
argument_list|(
argument|QWidget *keywidget
argument_list|,
argument|const XEvent *
argument_list|,
argument|KeySym&keysym
argument_list|,
argument|int& count
argument_list|,
argument|QString& text
argument_list|,
argument|Qt::KeyboardModifiers& modifiers
argument_list|,
argument|int&code
argument_list|,
argument|QEvent::Type&type
argument_list|,
argument|bool statefulTranslation = true
argument_list|)
block|;
name|bool
name|translateKeyEvent
argument_list|(
argument|QWidget *keywidget
argument_list|,
argument|const XEvent *
argument_list|,
argument|bool grab
argument_list|)
block|;
name|int
name|xkb_currentGroup
block|;
name|QXCoreDesc
name|coreDesc
block|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_WS_MAC
argument_list|)
name|bool
name|updateKeyboard
argument_list|()
block|;
name|void
name|updateKeyMap
argument_list|(
name|EventHandlerCallRef
argument_list|,
name|EventRef
argument_list|,
name|void
operator|*
argument_list|)
block|;
name|bool
name|translateKeyEvent
argument_list|(
name|QWidget
operator|*
argument_list|,
name|EventHandlerCallRef
argument_list|,
name|EventRef
argument_list|,
name|void
operator|*
argument_list|,
name|bool
argument_list|)
block|;
name|void
name|deleteLayouts
argument_list|()
block|;      enum
block|{
name|NullMode
block|,
name|UnicodeMode
block|,
name|OtherMode
block|}
name|keyboard_mode
block|;
expr|union
block|{
specifier|const
name|UCKeyboardLayout
operator|*
name|unicode
block|;
name|void
operator|*
name|other
block|;     }
name|keyboard_layout_format
block|;
ifdef|#
directive|ifdef
name|Q_WS_MAC64
name|QCFType
operator|<
name|TISInputSourceRef
operator|>
name|currentInputSource
block|;
else|#
directive|else
name|KeyboardLayoutRef
name|currentKeyboardLayout
block|;
endif|#
directive|endif
name|KeyboardLayoutKind
name|keyboard_kind
block|;
name|UInt32
name|keyboard_dead
block|;
name|KeyboardLayoutItem
operator|*
name|keyLayout
index|[
literal|256
index|]
block|;
elif|#
directive|elif
name|defined
argument_list|(
name|Q_WS_QWS
argument_list|)
elif|#
directive|elif
name|defined
argument_list|(
name|Q_OS_SYMBIAN
argument_list|)
name|public
operator|:
name|QString
name|translateKeyEvent
argument_list|(
argument|int keySym
argument_list|,
argument|Qt::KeyboardModifiers modifiers
argument_list|)
block|;
name|int
name|mapS60KeyToQt
argument_list|(
argument|TUint s60key
argument_list|)
block|;
name|int
name|mapS60ScanCodesToQt
argument_list|(
argument|TUint s60key
argument_list|)
block|;
name|int
name|mapQtToS60Key
argument_list|(
argument|int qtKey
argument_list|)
block|;
name|int
name|mapQtToS60ScanCodes
argument_list|(
argument|int qtKey
argument_list|)
block|;
name|void
name|updateInputLanguage
argument_list|()
block|;
endif|#
directive|endif
block|}
decl_stmt|;
end_decl_stmt
begin_function_decl
name|QKeyMapperPrivate
modifier|*
name|qt_keymapper_private
parameter_list|()
function_decl|;
end_function_decl
begin_comment
comment|// from qkeymapper.cpp
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QKEYMAPPER_P_H
end_comment
end_unit
