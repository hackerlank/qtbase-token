begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCOCOAKEYMAPPER_H
end_ifndef
begin_define
DECL|macro|QCOCOAKEYMAPPER_H
define|#
directive|define
name|QCOCOAKEYMAPPER_H
end_define
begin_include
include|#
directive|include
file|<qcocoahelpers.h>
end_include
begin_include
include|#
directive|include
file|<Cocoa/Cocoa.h>
end_include
begin_include
include|#
directive|include
file|<Carbon/Carbon.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QList>
end_include
begin_include
include|#
directive|include
file|<QtGui/QKeyEvent>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_comment
comment|/*     \internal     A Mac KeyboardLayoutItem has 8 possible states:         1. Unmodified         2. Shift         3. Control         4. Control + Shift         5. Alt         6. Alt + Shift         7. Alt + Control         8. Alt + Control + Shift         9. Meta         10. Meta + Shift         11. Meta + Control         12. Meta + Control + Shift         13. Meta + Alt         14. Meta + Alt + Shift         15. Meta + Alt + Control         16. Meta + Alt + Control + Shift */
end_comment
begin_struct
DECL|struct|KeyboardLayoutItem
struct|struct
name|KeyboardLayoutItem
block|{
DECL|member|dirty
name|bool
name|dirty
decl_stmt|;
DECL|member|qtKey
name|quint32
name|qtKey
index|[
literal|16
index|]
decl_stmt|;
comment|// Can by any Qt::Key_<foo>, or unicode character
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|QCocoaKeyMapper
block|{
name|public
label|:
name|QCocoaKeyMapper
argument_list|()
expr_stmt|;
operator|~
name|QCocoaKeyMapper
argument_list|()
expr_stmt|;
name|QList
operator|<
name|int
operator|>
name|possibleKeys
argument_list|(
argument|const QKeyEvent *event
argument_list|)
specifier|const
expr_stmt|;
name|bool
name|updateKeyboard
parameter_list|()
function_decl|;
name|void
name|deleteLayouts
parameter_list|()
function_decl|;
name|void
name|updateKeyMap
parameter_list|(
name|unsigned
name|short
name|macVirtualKey
parameter_list|,
name|QChar
name|unicodeKey
parameter_list|)
function_decl|;
name|void
name|clearMappings
parameter_list|()
function_decl|;
name|private
label|:
name|QCFType
operator|<
name|TISInputSourceRef
operator|>
name|currentInputSource
expr_stmt|;
name|QLocale
name|keyboardInputLocale
decl_stmt|;
name|Qt
operator|::
name|LayoutDirection
name|keyboardInputDirection
expr_stmt|;
enum|enum
block|{
name|NullMode
block|,
name|UnicodeMode
block|,
name|OtherMode
block|}
name|keyboard_mode
enum|;
union|union
block|{
specifier|const
name|UCKeyboardLayout
modifier|*
name|unicode
decl_stmt|;
name|void
modifier|*
name|other
decl_stmt|;
block|}
name|keyboard_layout_format
union|;
name|KeyboardLayoutRef
name|currentKeyboardLayout
decl_stmt|;
name|KeyboardLayoutKind
name|keyboard_kind
decl_stmt|;
name|UInt32
name|keyboard_dead
decl_stmt|;
name|KeyboardLayoutItem
modifier|*
name|keyLayout
index|[
literal|256
index|]
decl_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
end_unit
