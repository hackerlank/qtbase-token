begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QBMPHANDLER_P_H
end_ifndef
begin_define
DECL|macro|QBMPHANDLER_P_H
define|#
directive|define
name|QBMPHANDLER_P_H
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
file|"QtGui/qimageiohandler.h"
end_include
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_IMAGEFORMAT_BMP
end_ifndef
begin_macro
name|QT_BEGIN_NAMESPACE
end_macro
begin_struct
DECL|struct|BMP_FILEHDR
struct|struct
name|BMP_FILEHDR
block|{
comment|// BMP file header
DECL|member|bfType
name|char
name|bfType
index|[
literal|2
index|]
decl_stmt|;
comment|// "BM"
DECL|member|bfSize
name|qint32
name|bfSize
decl_stmt|;
comment|// size of file
DECL|member|bfReserved1
name|qint16
name|bfReserved1
decl_stmt|;
DECL|member|bfReserved2
name|qint16
name|bfReserved2
decl_stmt|;
DECL|member|bfOffBits
name|qint32
name|bfOffBits
decl_stmt|;
comment|// pointer to the pixmap bits
block|}
struct|;
end_struct
begin_struct
DECL|struct|BMP_INFOHDR
struct|struct
name|BMP_INFOHDR
block|{
comment|// BMP information header
DECL|member|biSize
name|qint32
name|biSize
decl_stmt|;
comment|// size of this struct
DECL|member|biWidth
name|qint32
name|biWidth
decl_stmt|;
comment|// pixmap width
DECL|member|biHeight
name|qint32
name|biHeight
decl_stmt|;
comment|// pixmap height
DECL|member|biPlanes
name|qint16
name|biPlanes
decl_stmt|;
comment|// should be 1
DECL|member|biBitCount
name|qint16
name|biBitCount
decl_stmt|;
comment|// number of bits per pixel
DECL|member|biCompression
name|qint32
name|biCompression
decl_stmt|;
comment|// compression method
DECL|member|biSizeImage
name|qint32
name|biSizeImage
decl_stmt|;
comment|// size of image
DECL|member|biXPelsPerMeter
name|qint32
name|biXPelsPerMeter
decl_stmt|;
comment|// horizontal resolution
DECL|member|biYPelsPerMeter
name|qint32
name|biYPelsPerMeter
decl_stmt|;
comment|// vertical resolution
DECL|member|biClrUsed
name|qint32
name|biClrUsed
decl_stmt|;
comment|// number of colors used
DECL|member|biClrImportant
name|qint32
name|biClrImportant
decl_stmt|;
comment|// number of important colors
block|}
struct|;
end_struct
begin_decl_stmt
name|class
name|QBmpHandler
range|:
name|public
name|QImageIOHandler
block|{
name|public
operator|:
name|QBmpHandler
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
name|QByteArray
name|name
argument_list|()
specifier|const
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
name|BMP_FILEHDR
name|fileHeader
block|;
name|BMP_INFOHDR
name|infoHeader
block|;
name|int
name|startpos
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
comment|// QT_NO_IMAGEFORMAT_BMP
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QBMPHANDLER_P_H
end_comment
end_unit
