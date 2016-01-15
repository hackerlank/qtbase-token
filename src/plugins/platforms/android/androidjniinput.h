begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 BogDan Vatra<bogdan@kde.org> ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|ANDROIDJNIINPUT_H
end_ifndef
begin_define
DECL|macro|ANDROIDJNIINPUT_H
define|#
directive|define
name|ANDROIDJNIINPUT_H
end_define
begin_include
include|#
directive|include
file|<jni.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_include
include|#
directive|include
file|<QtCore/QRect>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|namespace
name|QtAndroidInput
block|{
comment|// Software keyboard support
name|void
name|showSoftwareKeyboard
parameter_list|(
name|int
name|top
parameter_list|,
name|int
name|left
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|height
parameter_list|,
name|int
name|inputHints
parameter_list|,
name|int
name|enterKeyType
parameter_list|)
function_decl|;
name|void
name|resetSoftwareKeyboard
parameter_list|()
function_decl|;
name|void
name|hideSoftwareKeyboard
parameter_list|()
function_decl|;
name|bool
name|isSoftwareKeyboardVisible
parameter_list|()
function_decl|;
name|QRect
name|softwareKeyboardRect
parameter_list|()
function_decl|;
name|void
name|updateSelection
parameter_list|(
name|int
name|selStart
parameter_list|,
name|int
name|selEnd
parameter_list|,
name|int
name|candidatesStart
parameter_list|,
name|int
name|candidatesEnd
parameter_list|)
function_decl|;
comment|// Software keyboard support
name|bool
name|registerNatives
parameter_list|(
name|JNIEnv
modifier|*
name|env
parameter_list|)
function_decl|;
block|}
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// ANDROIDJNIINPUT_H
end_comment
end_unit
