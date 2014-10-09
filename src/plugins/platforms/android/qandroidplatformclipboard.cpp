begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2012 BogDan Vatra<bogdan@kde.org> ** Contact: http://www.qt-project.org/legal ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL21$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia. For licensing terms and ** conditions see http://qt.digia.com/licensing. For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 or version 3 as published by the Free ** Software Foundation and appearing in the file LICENSE.LGPLv21 and ** LICENSE.LGPLv3 included in the packaging of this file. Please review the ** following information to ensure the GNU Lesser General Public License ** requirements will be met: https://www.gnu.org/licenses/lgpl.html and ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights. These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qandroidplatformclipboard.h"
end_include
begin_include
include|#
directive|include
file|"androidjniclipboard.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
end_ifndef
begin_function
name|QT_BEGIN_NAMESPACE
DECL|function|QAndroidPlatformClipboard
name|QAndroidPlatformClipboard
operator|::
name|QAndroidPlatformClipboard
parameter_list|()
block|{
name|QtAndroidClipboard
operator|::
name|setClipboardListener
argument_list|(
name|this
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|mimeData
name|QMimeData
modifier|*
name|QAndroidPlatformClipboard
operator|::
name|mimeData
parameter_list|(
name|QClipboard
operator|::
name|Mode
name|mode
parameter_list|)
block|{
if|if
condition|(
name|QClipboard
operator|::
name|Clipboard
operator|!=
name|mode
operator|||
operator|!
name|QtAndroidClipboard
operator|::
name|hasClipboardText
argument_list|()
condition|)
return|return
literal|0
return|;
name|m_mimeData
operator|.
name|setText
argument_list|(
name|QtAndroidClipboard
operator|::
name|clipboardText
argument_list|()
argument_list|)
expr_stmt|;
return|return
operator|&
name|m_mimeData
return|;
block|}
end_function
begin_function
DECL|function|setMimeData
name|void
name|QAndroidPlatformClipboard
operator|::
name|setMimeData
parameter_list|(
name|QMimeData
modifier|*
name|data
parameter_list|,
name|QClipboard
operator|::
name|Mode
name|mode
parameter_list|)
block|{
name|Q_ASSERT
argument_list|(
name|supportsMode
argument_list|(
name|mode
argument_list|)
argument_list|)
expr_stmt|;
name|QtAndroidClipboard
operator|::
name|setClipboardText
argument_list|(
name|data
operator|!=
literal|0
operator|&&
name|data
operator|->
name|hasText
argument_list|()
condition|?
name|data
operator|->
name|text
argument_list|()
else|:
name|QString
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_function
begin_function
DECL|function|supportsMode
name|bool
name|QAndroidPlatformClipboard
operator|::
name|supportsMode
parameter_list|(
name|QClipboard
operator|::
name|Mode
name|mode
parameter_list|)
specifier|const
block|{
return|return
name|QClipboard
operator|::
name|Clipboard
operator|==
name|mode
return|;
block|}
end_function
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_CLIPBOARD
end_comment
end_unit
