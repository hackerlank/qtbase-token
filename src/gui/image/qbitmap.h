begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies). ** All rights reserved. ** Contact: Nokia Corporation (qt-info@nokia.com) ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** GNU Lesser General Public License Usage ** This file may be used under the terms of the GNU Lesser General Public ** License version 2.1 as published by the Free Software Foundation and ** appearing in the file LICENSE.LGPL included in the packaging of this ** file. Please review the following information to ensure the GNU Lesser ** General Public License version 2.1 requirements will be met: ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Nokia gives you certain additional ** rights. These rights are described in the Nokia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU General ** Public License version 3.0 as published by the Free Software Foundation ** and appearing in the file LICENSE.GPL included in the packaging of this ** file. Please review the following information to ensure the GNU General ** Public License version 3.0 requirements will be met: ** http://www.gnu.org/copyleft/gpl.html. ** ** Other Usage ** Alternatively, this file may be used in accordance with the terms and ** conditions contained in a signed written agreement between you and Nokia. ** ** ** ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QBITMAP_H
end_ifndef
begin_define
DECL|macro|QBITMAP_H
define|#
directive|define
name|QBITMAP_H
end_define
begin_include
include|#
directive|include
file|<QtGui/qpixmap.h>
end_include
begin_decl_stmt
name|QT_BEGIN_HEADER
name|QT_BEGIN_NAMESPACE
name|QT_MODULE
argument_list|(
name|Gui
argument_list|)
name|class
name|QVariant
decl_stmt|;
end_decl_stmt
begin_decl_stmt
name|class
name|Q_GUI_EXPORT
name|QBitmap
range|:
name|public
name|QPixmap
block|{
name|public
operator|:
name|QBitmap
argument_list|()
block|;
name|QBitmap
argument_list|(
specifier|const
name|QPixmap
operator|&
argument_list|)
block|;
name|QBitmap
argument_list|(
argument|int w
argument_list|,
argument|int h
argument_list|)
block|;
name|explicit
name|QBitmap
argument_list|(
specifier|const
name|QSize
operator|&
argument_list|)
block|;
name|explicit
name|QBitmap
argument_list|(
specifier|const
name|QString
operator|&
name|fileName
argument_list|,
specifier|const
name|char
operator|*
name|format
operator|=
literal|0
argument_list|)
block|;
operator|~
name|QBitmap
argument_list|()
block|;
name|QBitmap
operator|&
name|operator
operator|=
operator|(
specifier|const
name|QPixmap
operator|&
operator|)
block|;
specifier|inline
name|void
name|swap
argument_list|(
argument|QBitmap&other
argument_list|)
block|{
name|QPixmap
operator|::
name|swap
argument_list|(
name|other
argument_list|)
block|; }
comment|// prevent QBitmap<->QPixmap swaps
name|operator
name|QVariant
argument_list|()
specifier|const
block|;
specifier|inline
name|void
name|clear
argument_list|()
block|{
name|fill
argument_list|(
name|Qt
operator|::
name|color0
argument_list|)
block|; }
specifier|static
name|QBitmap
name|fromImage
argument_list|(
argument|const QImage&image
argument_list|,
argument|Qt::ImageConversionFlags flags = Qt::AutoColor
argument_list|)
block|;
specifier|static
name|QBitmap
name|fromData
argument_list|(
argument|const QSize&size
argument_list|,
argument|const uchar *bits
argument_list|,
argument|QImage::Format monoFormat = QImage::Format_MonoLSB
argument_list|)
block|;
name|QBitmap
name|transformed
argument_list|(
argument|const QMatrix&
argument_list|)
specifier|const
block|;
name|QBitmap
name|transformed
argument_list|(
argument|const QTransform&matrix
argument_list|)
specifier|const
block|;
typedef|typedef
name|QExplicitlySharedDataPointer
operator|<
name|QPlatformPixmap
operator|>
name|DataPtr
expr_stmt|;
block|}
end_decl_stmt
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|Q_DECLARE_SHARED
argument_list|(
argument|QBitmap
argument_list|)
end_macro
begin_expr_stmt
name|QT_END_NAMESPACE
name|QT_END_HEADER
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QBITMAP_H
end_comment
end_unit
