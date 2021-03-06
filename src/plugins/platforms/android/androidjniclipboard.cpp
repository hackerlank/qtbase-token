begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 BogDan Vatra<bogdan@kde.org> ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"androidjniclipboard.h"
end_include
begin_include
include|#
directive|include
file|"androidjnimain.h"
end_include
begin_include
include|#
directive|include
file|<QtCore/private/qjni_p.h>
end_include
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_using
using|using
namespace|namespace
name|QtAndroid
namespace|;
end_using
begin_namespace
DECL|namespace|QtAndroidClipboard
namespace|namespace
name|QtAndroidClipboard
block|{
DECL|function|setClipboardListener
name|void
name|setClipboardListener
parameter_list|(
name|QAndroidPlatformClipboard
modifier|*
name|listener
parameter_list|)
block|{
name|Q_UNUSED
argument_list|(
name|listener
argument_list|)
expr_stmt|;
name|QJNIObjectPrivate
operator|::
name|callStaticMethod
argument_list|<
name|void
argument_list|>
argument_list|(
name|applicationClass
argument_list|()
argument_list|,
literal|"registerClipboardManager"
argument_list|)
expr_stmt|;
block|}
DECL|function|setClipboardText
name|void
name|setClipboardText
parameter_list|(
specifier|const
name|QString
modifier|&
name|text
parameter_list|)
block|{
name|QJNIObjectPrivate
operator|::
name|callStaticMethod
argument_list|<
name|void
argument_list|>
argument_list|(
name|applicationClass
argument_list|()
argument_list|,
literal|"setClipboardText"
argument_list|,
literal|"(Ljava/lang/String;)V"
argument_list|,
name|QJNIObjectPrivate
operator|::
name|fromString
argument_list|(
name|text
argument_list|)
operator|.
name|object
argument_list|()
argument_list|)
expr_stmt|;
block|}
DECL|function|hasClipboardText
name|bool
name|hasClipboardText
parameter_list|()
block|{
return|return
name|QJNIObjectPrivate
operator|::
name|callStaticMethod
argument_list|<
name|jboolean
argument_list|>
argument_list|(
name|applicationClass
argument_list|()
argument_list|,
literal|"hasClipboardText"
argument_list|)
return|;
block|}
DECL|function|clipboardText
name|QString
name|clipboardText
parameter_list|()
block|{
name|QJNIObjectPrivate
name|text
init|=
name|QJNIObjectPrivate
operator|::
name|callStaticObjectMethod
argument_list|(
name|applicationClass
argument_list|()
argument_list|,
literal|"getClipboardText"
argument_list|,
literal|"()Ljava/lang/String;"
argument_list|)
decl_stmt|;
return|return
name|text
operator|.
name|toString
argument_list|()
return|;
block|}
block|}
end_namespace
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
