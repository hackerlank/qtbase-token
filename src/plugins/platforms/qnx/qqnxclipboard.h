begin_unit
begin_comment
comment|/*************************************************************************** ** ** Copyright (C) 2011 - 2012 Research In Motion ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the plugins of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QQNXCLIPBOARD_H
end_ifndef
begin_define
DECL|macro|QQNXCLIPBOARD_H
define|#
directive|define
name|QQNXCLIPBOARD_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|QT_NO_CLIPBOARD
argument_list|)
end_if
begin_include
include|#
directive|include
file|<qpa/qplatformclipboard.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QQnxClipboard
range|:
name|public
name|QPlatformClipboard
block|{
name|public
operator|:
name|QQnxClipboard
argument_list|()
block|;
operator|~
name|QQnxClipboard
argument_list|()
block|;
name|QMimeData
operator|*
name|mimeData
argument_list|(
argument|QClipboard::Mode mode = QClipboard::Clipboard
argument_list|)
block|;
name|void
name|setMimeData
argument_list|(
argument|QMimeData *data
argument_list|,
argument|QClipboard::Mode mode = QClipboard::Clipboard
argument_list|)
block|;
name|private
operator|:
name|class
name|MimeData
block|;
name|MimeData
operator|*
name|m_mimeData
block|; }
decl_stmt|;
end_decl_stmt
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QT_NO_CLIPBOARD
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|//QQNXCLIPBOARD_H
end_comment
end_unit
