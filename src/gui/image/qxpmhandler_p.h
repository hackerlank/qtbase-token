begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QXPMHANDLER_P_H
end_ifndef
begin_define
DECL|macro|QXPMHANDLER_P_H
define|#
directive|define
name|QXPMHANDLER_P_H
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
comment|// This file is not part of the Qt API.  It exists for the convenience
end_comment
begin_comment
comment|// of the QLibrary class.  This header file may change from
end_comment
begin_comment
comment|// version to version without notice, or even be removed.
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
file|"QtGui/qimageiohandler.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_IMAGEFORMAT_XPM
end_ifndef
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
name|class
name|QXpmHandler
range|:
name|public
name|QImageIOHandler
block|{
name|public
operator|:
name|QXpmHandler
argument_list|()
block|;
name|bool
name|canRead
argument_list|()
specifier|const
block|;
name|bool
name|read
argument_list|(
name|QImage
operator|*
name|image
argument_list|)
block|;
name|bool
name|write
argument_list|(
specifier|const
name|QImage
operator|&
name|image
argument_list|)
block|;
specifier|static
name|bool
name|canRead
argument_list|(
name|QIODevice
operator|*
name|device
argument_list|)
block|;
name|QByteArray
name|name
argument_list|()
specifier|const
block|;
name|QVariant
name|option
argument_list|(
argument|ImageOption option
argument_list|)
specifier|const
block|;
name|void
name|setOption
argument_list|(
argument|ImageOption option
argument_list|,
argument|const QVariant&value
argument_list|)
block|;
name|bool
name|supportsOption
argument_list|(
argument|ImageOption option
argument_list|)
specifier|const
block|;
name|private
operator|:
name|bool
name|readHeader
argument_list|()
block|;
name|bool
name|readImage
argument_list|(
name|QImage
operator|*
name|image
argument_list|)
block|;     enum
name|State
block|{
name|Ready
block|,
name|ReadHeader
block|,
name|Error
block|}
block|;
name|State
name|state
block|;
name|int
name|width
block|;
name|int
name|height
block|;
name|int
name|ncols
block|;
name|int
name|cpp
block|;
name|QByteArray
name|buffer
block|;
name|int
name|index
block|;
name|QString
name|fileName
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
comment|// QT_NO_IMAGEFORMAT_XPM
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QXPMHANDLER_P_H
end_comment
end_unit
