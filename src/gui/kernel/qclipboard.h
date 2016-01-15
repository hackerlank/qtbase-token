begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QCLIPBOARD_H
end_ifndef
begin_define
DECL|macro|QCLIPBOARD_H
define|#
directive|define
name|QCLIPBOARD_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qobject.h>
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_CLIPBOARD
DECL|variable|QMimeData
name|class
name|QMimeData
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QImage
name|class
name|QImage
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPixmap
name|class
name|QPixmap
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QClipboard
range|:
name|public
name|QObject
block|{
name|Q_OBJECT
name|private
operator|:
name|explicit
name|QClipboard
argument_list|(
name|QObject
operator|*
name|parent
argument_list|)
block|;
operator|~
name|QClipboard
argument_list|()
block|;
name|public
operator|:
expr|enum
name|Mode
block|{
name|Clipboard
block|,
name|Selection
block|,
name|FindBuffer
block|,
name|LastMode
operator|=
name|FindBuffer
block|}
block|;
name|void
name|clear
argument_list|(
argument|Mode mode = Clipboard
argument_list|)
block|;
name|bool
name|supportsSelection
argument_list|()
specifier|const
block|;
name|bool
name|supportsFindBuffer
argument_list|()
specifier|const
block|;
name|bool
name|ownsSelection
argument_list|()
specifier|const
block|;
name|bool
name|ownsClipboard
argument_list|()
specifier|const
block|;
name|bool
name|ownsFindBuffer
argument_list|()
specifier|const
block|;
name|QString
name|text
argument_list|(
argument|Mode mode = Clipboard
argument_list|)
specifier|const
block|;
name|QString
name|text
argument_list|(
argument|QString& subtype
argument_list|,
argument|Mode mode = Clipboard
argument_list|)
specifier|const
block|;
name|void
name|setText
argument_list|(
argument|const QString&
argument_list|,
argument|Mode mode = Clipboard
argument_list|)
block|;
specifier|const
name|QMimeData
operator|*
name|mimeData
argument_list|(
argument|Mode mode = Clipboard
argument_list|)
specifier|const
block|;
name|void
name|setMimeData
argument_list|(
argument|QMimeData *data
argument_list|,
argument|Mode mode = Clipboard
argument_list|)
block|;
name|QImage
name|image
argument_list|(
argument|Mode mode = Clipboard
argument_list|)
specifier|const
block|;
name|QPixmap
name|pixmap
argument_list|(
argument|Mode mode = Clipboard
argument_list|)
specifier|const
block|;
name|void
name|setImage
argument_list|(
argument|const QImage&
argument_list|,
argument|Mode mode  = Clipboard
argument_list|)
block|;
name|void
name|setPixmap
argument_list|(
argument|const QPixmap&
argument_list|,
argument|Mode mode  = Clipboard
argument_list|)
block|;
name|Q_SIGNALS
operator|:
name|void
name|changed
argument_list|(
argument|QClipboard::Mode mode
argument_list|)
block|;
name|void
name|selectionChanged
argument_list|()
block|;
name|void
name|findBufferChanged
argument_list|()
block|;
name|void
name|dataChanged
argument_list|()
block|;
name|protected
operator|:
name|friend
name|class
name|QApplication
block|;
name|friend
name|class
name|QApplicationPrivate
block|;
name|friend
name|class
name|QGuiApplication
block|;
name|friend
name|class
name|QBaseApplication
block|;
name|friend
name|class
name|QDragManager
block|;
name|friend
name|class
name|QPlatformClipboard
block|;
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QClipboard
argument_list|)
name|bool
name|supportsMode
argument_list|(
argument|Mode mode
argument_list|)
specifier|const
block|;
name|bool
name|ownsMode
argument_list|(
argument|Mode mode
argument_list|)
specifier|const
block|;
name|void
name|emitChanged
argument_list|(
argument|Mode mode
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_CLIPBOARD
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QCLIPBOARD_H
end_comment
end_unit
