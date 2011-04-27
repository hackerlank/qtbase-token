begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** No Commercial Usage ** This file contains pre-release code and may not be distributed. ** You may use this file in accordance with the terms and conditions ** contained in the Technology Preview License Agreement accompanying ** this package. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights.  These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** If you have questions regarding the use of this file, please contact ** Nokia at qt-info@nokia.com. ** ** ** ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QPRINTENGINE_PS_P_H
end_ifndef
begin_define
DECL|macro|QPRINTENGINE_PS_P_H
define|#
directive|define
name|QPRINTENGINE_PS_P_H
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
comment|// of qpsprinter.cpp and qprinter_x11.cpp.
end_comment
begin_comment
comment|// This header file may change from version to version without notice,
end_comment
begin_comment
comment|// or even be removed.
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
begin_ifndef
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
end_ifndef
begin_include
include|#
directive|include
file|"private/qpdf_p.h"
end_include
begin_include
include|#
directive|include
file|"qplatformdefs.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qlibrary.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qstringlist.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qhash.h"
end_include
begin_include
include|#
directive|include
file|"QtCore/qabstractitemmodel.h"
end_include
begin_decl_stmt
name|QT_BEGIN_NAMESPACE
DECL|variable|QPrinter
name|class
name|QPrinter
decl_stmt|;
end_decl_stmt
begin_decl_stmt
DECL|variable|QPSPrintEnginePrivate
name|class
name|QPSPrintEnginePrivate
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|QPSPrintEngine
range|:
name|public
name|QPdfBaseEngine
block|{
name|Q_DECLARE_PRIVATE
argument_list|(
argument|QPSPrintEngine
argument_list|)
name|public
operator|:
comment|// QPrinter uses these
name|explicit
name|QPSPrintEngine
argument_list|(
argument|QPrinter::PrinterMode m
argument_list|)
block|;
operator|~
name|QPSPrintEngine
argument_list|()
block|;
name|virtual
name|bool
name|begin
argument_list|(
name|QPaintDevice
operator|*
name|pdev
argument_list|)
block|;
name|virtual
name|bool
name|end
argument_list|()
block|;
name|void
name|setBrush
argument_list|()
block|;
name|virtual
name|void
name|drawImage
argument_list|(
specifier|const
name|QRectF
operator|&
name|r
argument_list|,
specifier|const
name|QImage
operator|&
name|img
argument_list|,
specifier|const
name|QRectF
operator|&
name|sr
argument_list|,
name|Qt
operator|::
name|ImageConversionFlags
argument_list|)
block|;
name|virtual
name|void
name|drawPixmap
argument_list|(
specifier|const
name|QRectF
operator|&
name|r
argument_list|,
specifier|const
name|QPixmap
operator|&
name|pm
argument_list|,
specifier|const
name|QRectF
operator|&
name|sr
argument_list|)
block|;
name|virtual
name|void
name|drawTiledPixmap
argument_list|(
specifier|const
name|QRectF
operator|&
name|r
argument_list|,
specifier|const
name|QPixmap
operator|&
name|pixmap
argument_list|,
specifier|const
name|QPointF
operator|&
name|s
argument_list|)
block|;
name|virtual
name|void
name|drawImageInternal
argument_list|(
argument|const QRectF&r
argument_list|,
argument|QImage img
argument_list|,
argument|bool bitmap
argument_list|)
block|;
name|virtual
name|QPaintEngine
operator|::
name|Type
name|type
argument_list|()
specifier|const
block|{
return|return
name|QPaintEngine
operator|::
name|PostScript
return|;
block|}
name|virtual
name|bool
name|newPage
argument_list|()
block|;
name|virtual
name|bool
name|abort
argument_list|()
block|;
name|virtual
name|QPrinter
operator|::
name|PrinterState
name|printerState
argument_list|()
specifier|const
block|;
name|virtual
name|Qt
operator|::
name|HANDLE
name|handle
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
name|private
operator|:
name|Q_DISABLE_COPY
argument_list|(
argument|QPSPrintEngine
argument_list|)
expr|}
block|;
name|class
name|QPSPrintEnginePrivate
operator|:
name|public
name|QPdfBaseEnginePrivate
block|{
name|public
operator|:
name|QPSPrintEnginePrivate
argument_list|(
argument|QPrinter::PrinterMode m
argument_list|)
block|;
operator|~
name|QPSPrintEnginePrivate
argument_list|()
block|;
name|void
name|emitHeader
argument_list|(
argument|bool finished
argument_list|)
block|;
name|void
name|emitPages
argument_list|()
block|;
name|void
name|drawImage
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|,
argument|qreal w
argument_list|,
argument|qreal h
argument_list|,
argument|const QImage&img
argument_list|,
argument|const QImage&mask
argument_list|)
block|;
name|void
name|flushPage
argument_list|(
argument|bool last = false
argument_list|)
block|;
name|void
name|drawImageHelper
argument_list|(
argument|qreal x
argument_list|,
argument|qreal y
argument_list|,
argument|qreal w
argument_list|,
argument|qreal h
argument_list|,
argument|const QImage&img
argument_list|,
argument|const QImage&mask
argument_list|,
argument|bool gray
argument_list|,
argument|qreal scaleX
argument_list|,
argument|qreal scaleY
argument_list|)
block|;
name|int
name|pageCount
block|;
name|bool
name|epsf
block|;
name|QByteArray
name|fontsUsed
block|;
comment|// stores the descriptions of the n first pages.
name|QPdf
operator|::
name|ByteStream
name|buffer
block|;
name|QByteArray
name|trailer
block|;
name|bool
name|firstPage
block|;
name|QRect
name|boundingBox
block|;
name|QPrinter
operator|::
name|PrinterState
name|printerState
block|;
name|bool
name|hugeDocument
block|;
name|bool
name|headerDone
block|; }
block|;
name|QT_END_NAMESPACE
end_decl_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_PRINTER
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QPRINTENGINE_PS_P_H
end_comment
end_unit
